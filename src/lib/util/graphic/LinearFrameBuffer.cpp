/*
 * Copyright (C) 2018-2022 Heinrich-Heine-Universitaet Duesseldorf,
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

#include "lib/util/Exception.h"
#include "lib/util/stream/FileInputStream.h"
#include "lib/interface.h"
#include "lib/util/math/Math.h"
#include "LinearFrameBuffer.h"

namespace Util::Graphic {

    LinearFrameBuffer::LinearFrameBuffer(uint32_t physicalAddress, uint16_t resolutionX, uint16_t resolutionY,
                                         uint8_t colorDepth, uint16_t pitch, bool enableAcceleration) :
            buffer(enableAcceleration ? Memory::Address<uint32_t>::createAcceleratedAddress(
                    reinterpret_cast<uint32_t>(mapIO(physicalAddress, pitch * resolutionY)), useMmx)
                                      : new Memory::Address<uint32_t>(mapIO(physicalAddress, pitch * resolutionY))),
            resolutionX(resolutionX), resolutionY(resolutionY), colorDepth(colorDepth), pitch(pitch) {}

    LinearFrameBuffer::LinearFrameBuffer(void *virtualAddress, uint16_t resolutionX, uint16_t resolutionY,
                                         uint8_t colorDepth, uint16_t pitch, bool enableAcceleration) :
            buffer(enableAcceleration ? Memory::Address<uint32_t>::createAcceleratedAddress(
                    reinterpret_cast<uint32_t>(virtualAddress), useMmx) : new Memory::Address<uint32_t>(
                    virtualAddress)), resolutionX(resolutionX), resolutionY(resolutionY), colorDepth(colorDepth),
            pitch(pitch) {}

    LinearFrameBuffer::LinearFrameBuffer(Util::Memory::Address<uint32_t> *address, uint16_t resolutionX,
                                         uint16_t resolutionY, uint8_t colorDepth, uint16_t pitch) :
            buffer(address), resolutionX(resolutionX), resolutionY(resolutionY), colorDepth(colorDepth), pitch(pitch) {}

    LinearFrameBuffer::LinearFrameBuffer(File::File &file, bool enableAcceleration) {
        if (!file.exists()) {
            Exception::throwException(Exception::INVALID_ARGUMENT, "LinearFrameBuffer: File does not exist!");
        }

        uint8_t addressBuffer[16];
        uint8_t xBuffer[16];
        uint8_t yBuffer[16];
        uint8_t bppBuffer[16];
        uint8_t pitchBuffer[16];

        Util::Memory::Address<uint32_t>(addressBuffer).setRange(0, sizeof(addressBuffer));
        Util::Memory::Address<uint32_t>(xBuffer).setRange(0, sizeof(xBuffer));
        Util::Memory::Address<uint32_t>(yBuffer).setRange(0, sizeof(yBuffer));
        Util::Memory::Address<uint32_t>(bppBuffer).setRange(0, sizeof(bppBuffer));
        Util::Memory::Address<uint32_t>(pitchBuffer).setRange(0, sizeof(pitchBuffer));

        auto stream = Stream::FileInputStream(file);
        int16_t currentChar;

        for (unsigned char &i: addressBuffer) {
            currentChar = stream.read();
            if (currentChar == '\n') {
                break;
            }

            i = currentChar;
        }

        for (unsigned char &i: xBuffer) {
            currentChar = stream.read();
            if (currentChar == 'x') {
                break;
            }

            i = currentChar;
        }

        for (unsigned char &i: yBuffer) {
            currentChar = stream.read();
            if (currentChar == '@') {
                break;
            }

            i = currentChar;
        }

        for (unsigned char &i: bppBuffer) {
            currentChar = stream.read();
            if (currentChar == '\n') {
                break;
            }

            i = currentChar;
        }

        for (unsigned char &i: pitchBuffer) {
            currentChar = stream.read();
            if (currentChar == -1) {
                break;
            }

            i = currentChar;
        }

        uint32_t address = Util::Memory::String::parseInt(reinterpret_cast<const char *>(addressBuffer));
        resolutionX = Util::Memory::String::parseInt(reinterpret_cast<const char *>(xBuffer));
        resolutionY = Util::Memory::String::parseInt(reinterpret_cast<const char *>(yBuffer));
        colorDepth = Util::Memory::String::parseInt(reinterpret_cast<const char *>(bppBuffer));
        pitch = Util::Memory::String::parseInt(reinterpret_cast<const char *>(pitchBuffer));
        buffer = enableAcceleration ? Memory::Address<uint32_t>::createAcceleratedAddress(
                reinterpret_cast<uint32_t>(mapIO(address, pitch * resolutionY)), useMmx)
                                    : new Memory::Address<uint32_t>(mapIO(address, pitch * resolutionY));
    }

    LinearFrameBuffer::~LinearFrameBuffer() {
        delete reinterpret_cast<uint8_t *>(buffer->get());
        delete buffer;
    }

    uint16_t LinearFrameBuffer::getResolutionX() const {
        return resolutionX;
    }

    uint16_t LinearFrameBuffer::getResolutionY() const {
        return resolutionY;
    }

    uint8_t LinearFrameBuffer::getColorDepth() const {
        return colorDepth;
    }

    uint16_t LinearFrameBuffer::getPitch() const {
        return pitch;
    }

    Memory::Address<uint32_t> LinearFrameBuffer::getBuffer() const {
        return *buffer;
    }

    Color LinearFrameBuffer::readPixel(uint16_t x, uint16_t y) const {
        if (x > resolutionX - 1 || y > resolutionY - 1) {
            Exception::throwException(Exception::OUT_OF_BOUNDS,
                                      "LinearFrameBuffer: Trying to read a pixel out of bounds!");
        }

        auto bpp = static_cast<uint8_t>(colorDepth == 15 ? 16 : colorDepth);
        auto address = buffer->add((x * (bpp / 8)) + y * pitch);

        return Color::fromRGB(*(reinterpret_cast<uint32_t *>(address.get())), colorDepth);
    }

    void LinearFrameBuffer::clear() const {
        buffer->setRange(0, getPitch() * getResolutionY());
        if (useMmx) {
            Math::Math::endMmx();
        }
    }

    void LinearFrameBuffer::clear(Color color) const {
        uint32_t shortValue = (0xFF << 24) | (color.getRed() << 16) | (color.getGreen() << 8) | color.getBlue();
        buffer->setRange32(shortValue, getPitch() * getResolutionY());
        if (useMmx) {
            Math::Math::endMmx();
        }
    }

    void LinearFrameBuffer::clear(const Memory::Address<uint32_t> &backgroundBuffer) const {
        buffer->copyRange(backgroundBuffer, getPitch() * getResolutionY());
        if (useMmx) {
            Math::Math::endMmx();
        }
    }

    void LinearFrameBuffer::clear(const Memory::Address<uint32_t> &backgroundBuffer, int xOffset) const {
        xOffset = xOffset % (getPitch());
        xOffset -= xOffset % 4;

        for (auto y = 0; y < getResolutionY(); y++) {
            auto bufferOffsetY = getPitch() * y;

            auto copyToAddr = Memory::Address<uint32_t>(buffer->get() + bufferOffsetY);
            auto toCopyAddr = Memory::Address<uint32_t>(backgroundBuffer.get() + bufferOffsetY + xOffset);
            copyToAddr.copyRange(toCopyAddr, getPitch() - xOffset);


            copyToAddr = Memory::Address<uint32_t>(buffer->get() + bufferOffsetY + (getPitch() - xOffset));
            toCopyAddr = Memory::Address<uint32_t>(backgroundBuffer.get() + bufferOffsetY);
            copyToAddr.copyRange(toCopyAddr, getPitch() - (getPitch() - xOffset));
        }
        if (useMmx) {
            Math::Math::endMmx();
        }
    }

}