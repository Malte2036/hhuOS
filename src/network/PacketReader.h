/*
 * Copyright (C) 2018-2022 Heinrich-Heine-Universitaet Duesseldorf,
 * Institute of Computer Science, Department Operating Systems
 * Burak Akguel, Christian Gesse, Fabian Ruhland, Filip Krakowski, Hannes Feil, Michael Schoettner
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

#ifndef HHUOS_PACKETREADER_H
#define HHUOS_PACKETREADER_H

#include "lib/util/async/Runnable.h"
#include "device/network/NetworkDevice.h"

namespace Network {

class PacketReader : public Util::Async::Runnable {

public:
    /**
     * Default Constructor.
     */
    explicit PacketReader(Device::Network::NetworkDevice *networkDevice);

    /**
     * Copy Constructor.
     */
    PacketReader(const PacketReader &other) = delete;

    /**
     * Assignment operator.
     */
    PacketReader &operator=(const PacketReader &other) = delete;

    /**
     * Destructor.
     */
    ~PacketReader() override;

    void run() override;

private:

    Device::Network::NetworkDevice *networkDevice;
};

}

#endif