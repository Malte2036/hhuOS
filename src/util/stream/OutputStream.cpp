/*
 * Copyright (C) 2021 Heinrich-Heine-Universitaet Duesseldorf,
 * Institute of Computer Science, Department Operating Systems
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPstreamE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <device/cpu/Cpu.h>
#include "OutputStream.h"

namespace Util::Stream  {

void OutputStream::write(const uint8_t *source, uint32_t offset, uint32_t length) {
    if (offset < 0 || length < 0) {
        Device::Cpu::throwException(Device::Cpu::Exception::OUT_OF_BOUNDS, "OutputStream: Negative offset or size!");
    }

    for (uint32_t i = 0; i < length; i++) {
        write(source[offset + i]);
    }
}

void OutputStream::flush() {

}

void OutputStream::close() {

}

OutputStream &OutputStream::operator<<(uint8_t c) {
    write(c);
    return *this;
}

}