/*
 * Copyright (C) 2018-2022 Heinrich-Heine-Universitaet Duesseldorf,
 * Institute of Computer Science, Department Operating Systems
 * Burak Akguel, Christian Gesse, Fabian Ruhland, Filip Krakowski, Hannes Feil,  Michael Schoettner
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

#include "Ip4Address.h"
#include "lib/util/memory/Address.h"

namespace Network::Ip4 {

Ip4Address::Ip4Address(uint8_t *buffer) {
    setAddress(buffer);
}

Ip4Address::Address Ip4Address::getAddress() {
    return address;
}

void Ip4Address::setAddress(uint8_t *buffer) {
    auto source = Util::Memory::Address<uint32_t>(buffer);
    auto destination = Util::Memory::Address<uint32_t>(address.buffer);
    destination.copyRange(source, ADDRESS_LENGTH);
}

void Ip4Address::readAddress(Util::Stream::InputStream &stream) {
    stream.read(address.buffer, 0, ADDRESS_LENGTH);
}

}