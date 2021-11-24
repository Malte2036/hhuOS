/*
 * Copyright (C) 2018-2021 Heinrich-Heine-Universitaet Duesseldorf,
 * Institute of Computer Science, Department Operating Systems
 * Burak Akguel, Christian Gesse, Fabian Ruhland, Filip Krakowski, Michael Schoettner
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <kernel/interrupt/InterruptDispatcher.h>
#include <device/interrupt/Pic.h>
#include "Pit.h"

namespace Device {

Pit::Pit(uint16_t interruptRateDivisor) {
    setInterruptRate(interruptRateDivisor);
}

void Pit::setInterruptRate(uint16_t divisor) {
    if (divisor == 0) {
        Util::Exception::throwException(Util::Exception::INVALID_ARGUMENT, "PIT: Divisor may not be set to 0!");
    }

    controlPort.writeByte(0x36); // Select channel 0, Use low-/high byte access mode, Set operating mode to rate generator
    dataPort0.writeByte((uint8_t) (divisor & 0xff)); // Low byte
    dataPort0.writeByte((uint8_t) (divisor >> 8)); // High byte

    timerInterval = static_cast<uint32_t>(1000000000 / (BASE_FREQUENCY / divisor));
}

void Pit::plugin() {
    Kernel::InterruptDispatcher::getInstance().assign(32, *this);
    Pic::getInstance().allow(Pic::Interrupt::PIT);
}

void Pit::trigger(Kernel::InterruptFrame &frame) {
    time.addNanoseconds(timerInterval);
    advanceTime(Util::Time::Timestamp(0, timerInterval));
    executePendingJobs();
}

Util::Time::Timestamp Pit::getTime() {
    return time;
}

}