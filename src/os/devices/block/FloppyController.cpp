#include <lib/libc/printf.h>
#include <kernel/services/TimeService.h>
#include <kernel/Kernel.h>
#include <devices/block/storage/FloppyDevice.h>
#include <kernel/threads/WorkerThread.h>
#include <kernel/interrupts/Pic.h>
#include <kernel/interrupts/IntDispatcher.h>
#include "FloppyController.h"

Logger &FloppyController::log = Logger::get("FLOPPY");

bool FloppyController::waitForMotorOff(FloppyDevice * const &device) {
    auto *timeService = Kernel::getService<TimeService>();
    uint32_t timeout = FloppyController::FLOPPY_TIMEOUT;

    while(timeout > 0) {
        if(device->motorState == FloppyController::FLOPPY_MOTOR_ON) {
            return false; // Should not happen
        } else if(device->motorState == FloppyController::FLOPPY_MOTOR_OFF) {
            return true; // Motor is already turned off
        }

        timeService->msleep(500);
        timeout -= 500;
    }

    device->controller.killMotor(*device); // Turn of the motor

    return true;
}

bool FloppyController::isAvailable() {
    IOport cmosRegisterPort(0x70);
    IOport cmosDataPort(0x71);

    cmosRegisterPort.outb(0x10);

    return cmosDataPort.inb() != 0;
}

FloppyController::FloppyController() :
        statusRegisterA(IO_BASE_ADDRESS + 0), statusRegisterB(IO_BASE_ADDRESS + 1), digitalOutputRegister(IO_BASE_ADDRESS + 2),
        tapeDriveRegister(IO_BASE_ADDRESS + 3), mainStatusRegister(IO_BASE_ADDRESS + 4), datarateSelectRegister(IO_BASE_ADDRESS + 4),
        fifoRegister(IO_BASE_ADDRESS + 5), digitalInputRegister(IO_BASE_ADDRESS + 7), configControlRegister(IO_BASE_ADDRESS + 7) {

    timeService = Kernel::getService<TimeService>();
    storageService = Kernel::getService<StorageService>();
}

bool FloppyController::isBusy() {
    return (mainStatusRegister.inb() & 0x10u) == 0x10;
}

bool FloppyController::isFifoBufferReady() {
    return (mainStatusRegister.inb() & 0x80u) == 0x80;
}

void FloppyController::setup() {
    IOport cmosRegisterPort(0x70);
    IOport cmosDataPort(0x71);

    cmosRegisterPort.outb(0x10);

    uint8_t driveInfo = cmosDataPort.inb();

    auto primaryDriveType = static_cast<DriveType>(driveInfo >> 4u);
    auto secondaryDriveType = static_cast<DriveType>(driveInfo & static_cast<uint8_t>(0xfu));

    if(primaryDriveType != DriveType::DRIVE_TYPE_NONE && primaryDriveType != DriveType::DRIVE_TYPE_UNKNOWN_1 &&
       primaryDriveType != DriveType::DRIVE_TYPE_UNKNOWN_2) {

        log.trace("Found primary floppy drive");

        storageService->registerDevice(new FloppyDevice(*this, 0, primaryDriveType, "fdd0"));
    }

    if(secondaryDriveType != DriveType::DRIVE_TYPE_NONE && secondaryDriveType != DriveType::DRIVE_TYPE_UNKNOWN_1 &&
       secondaryDriveType != DriveType::DRIVE_TYPE_UNKNOWN_2) {

        log.trace("Found secondary floppy drive");

        storageService->registerDevice(new FloppyDevice(*this, 1, secondaryDriveType, "fdd1"));
    }
}

void FloppyController::writeFifoByte(uint8_t command) {
    uint32_t timeout = 0;

    while(timeout < FLOPPY_TIMEOUT) {
        if(isFifoBufferReady()) {
            fifoRegister.outb(command);

            return;
        }

        timeService->msleep(10);
        timeout += 10;
    }

    log.error("Timeout while issuing write command!");
}

uint8_t FloppyController::readFifoByte() {
    uint32_t timeout = 0;

    while(timeout < FLOPPY_TIMEOUT) {
        if(isFifoBufferReady()) {
            return fifoRegister.inb();
        }

        timeService->msleep(10);
        timeout += 10;
    }

    log.error("Timeout while reading data!");

    return 0;
}

FloppyController::SenseInterruptState FloppyController::senseInterrupt() {
    SenseInterruptState ret{};

    writeFifoByte(COMMAND_SENSE_INTERRUPT);

    ret.statusRegister0 = readFifoByte();
    ret.currentCylinder = readFifoByte();

    return ret;
}

void FloppyController::setMotorState(FloppyDevice &device, FloppyController::FloppyMotorState desiredState) {
    if(desiredState == FLOPPY_MOTOR_WAIT) {
        return;
    } else if(desiredState == FLOPPY_MOTOR_ON) {
        if(motorState == FLOPPY_MOTOR_ON) {
            return;
        }

        digitalOutputRegister.outb(device.driveNumber | static_cast<uint8_t>(0x1c)); // Turn on the floppy motor
        timeService->msleep(1000); // Wait a second; This should be enough time, even for older drives

        motorState = FLOPPY_MOTOR_ON;
    } else if(desiredState == FLOPPY_MOTOR_OFF) {
        if(motorState == FLOPPY_MOTOR_OFF || motorState == FLOPPY_MOTOR_WAIT) {
            return;
        }

        motorState = FLOPPY_MOTOR_WAIT;

        WorkerThread<FloppyDevice*, bool> waitThread(waitForMotorOff, &device, nullptr);
    }
}

void FloppyController::killMotor(FloppyDevice &device) {
    digitalOutputRegister.outb(device.driveNumber | static_cast<uint8_t>(0x0c));
    motorState = FLOPPY_MOTOR_OFF;
}

bool FloppyController::resetDrive(FloppyDevice &device) {
    receivedInterrupt = false;

    digitalOutputRegister.outb(0x00); // Disable controller;
    digitalOutputRegister.outb(device.driveNumber | static_cast<uint8_t>(0x0c)); // Enable controller;

    while(!receivedInterrupt);

    senseInterrupt();

    switch(device.driveType) {
        case DRIVE_TYPE_360KB_5_25 :
            configControlRegister.outb(0x02);
        case DRIVE_TYPE_1200KB_5_25 :
            configControlRegister.outb(0x00);
        case DRIVE_TYPE_720KB_3_5 :
            configControlRegister.outb(0x01);
        case DRIVE_TYPE_1440KB_3_5 :
            configControlRegister.outb(0x00);
        case DRIVE_TYPE_2880KB_3_5 :
            configControlRegister.outb(0x00);
        default :
            configControlRegister.outb(0x03);
    }

    writeFifoByte(COMMAND_SPECIFY);
    writeFifoByte(0xdf);
    writeFifoByte(0x02);

    return calibrateDrive(device);
}

bool FloppyController::calibrateDrive(FloppyDevice &device) {
    log.trace("Calibrating drive %d", device.driveNumber);

    receivedInterrupt = false;

    setMotorState(device, FLOPPY_MOTOR_ON);

    for(uint8_t i = 0; i < FLOPPY_RETRY_COUNT; i++) {
        writeFifoByte(COMMAND_RECALIBRATE);
        writeFifoByte(device.driveNumber);

        while(!receivedInterrupt);
        SenseInterruptState interruptState = senseInterrupt();

        if((interruptState.statusRegister0 & 0xc0u) == 0xc0) {
            continue;
        }

        if(interruptState.currentCylinder == 0) {
            setMotorState(device, FLOPPY_MOTOR_OFF);

            log.trace("Successfully calibrated drive %d", device.driveNumber);

            return true;
        }
    }

    log.error("Failed to calibrate drive %u: Did not find cylinder 0", device.driveNumber);

    setMotorState(device, FLOPPY_MOTOR_OFF);

    return false;
}

bool FloppyController::seek(FloppyDevice &device, uint8_t cylinder, uint8_t head) {
    receivedInterrupt = false;

    setMotorState(device, FLOPPY_MOTOR_ON);

    for(uint8_t i = 0; i < FLOPPY_RETRY_COUNT; i++) {
        writeFifoByte(COMMAND_SEEK);
        writeFifoByte(device.driveNumber | static_cast<uint8_t>(head << 6u));
        writeFifoByte(cylinder);

        while(!receivedInterrupt);
        SenseInterruptState interruptState = senseInterrupt();

        if((interruptState.statusRegister0 & 0xc0u) == 0xc0) {
            continue;
        }

        if(interruptState.currentCylinder == 0) {
            setMotorState(device, FLOPPY_MOTOR_OFF);

            return true;
        }
    }

    log.error("Failed to seek on drive %u: Did not find cylinder %u", device.driveNumber, cylinder);

    setMotorState(device, FLOPPY_MOTOR_OFF);

    return false;
}

void FloppyController::plugin() {
    IntDispatcher::getInstance().assign(IntDispatcher::floppy, *this);
    Pic::getInstance()->allow(Pic::Interrupt::FLOPPY);
}

void FloppyController::trigger() {
    receivedInterrupt = true;
}