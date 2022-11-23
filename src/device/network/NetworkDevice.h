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

#ifndef HHUOS_NETWORKDEVICE_H
#define HHUOS_NETWORKDEVICE_H

#include "kernel/interrupt/InterruptHandler.h"
#include "kernel/memory/BitmapMemoryManager.h"
#include "lib/util/stream/FilterInputStream.h"
#include "lib/util/stream/OutputStream.h"
#include "lib/util/stream/PipedOutputStream.h"
#include "lib/util/stream/ByteArrayInputStream.h"
#include "lib/util/data/ArrayBlockingQueue.h"
#include "lib/util/async/ReentrantSpinlock.h"
#include "network/MacAddress.h"
#include "kernel/log/Logger.h"
#include "PacketReader.h"
#include "PacketWriter.h"
#include "network/ip4/Ip4Address.h"

namespace Device::Network {

/**
 * Interface for network cards
 */
class NetworkDevice {

friend class PacketReader;
friend class PacketWriter;

public:

    struct Packet {
        uint8_t *buffer;
        uint32_t length;

        bool operator==(const Packet &other) const;
    };

    /**
     * Default Constructor.
     */
    explicit NetworkDevice(const Util::Memory::String &identifier);

    /**
     * Copy-constructor.
     */
    NetworkDevice(const NetworkDevice &copy) = delete;

    /**
     * Assignment operator.
     */
    NetworkDevice &operator=(const NetworkDevice &other) = delete;

    /**
     * Destructor.
     */
    virtual ~NetworkDevice();

    [[nodiscard]] Util::Memory::String getIdentifier() const;

    [[nodiscard]] virtual ::Network::MacAddress getMacAddress() const = 0;

    void addAddress(const ::Network::NetworkAddress &address);

    void removeAddress(const ::Network::NetworkAddress &address);

    [[nodiscard]] bool hasAddress(const ::Network::NetworkAddress &address);

    [[nodiscard]] bool hasAddress(::Network::NetworkAddress::Type type);

    [[nodiscard]] ::Network::Ip4::Ip4Address getIp4Address();

    void sendPacket(const uint8_t *packet, uint32_t length);

    Packet getNextIncomingPacket();

    Packet getNextOutgoingPacket();

protected:

    virtual void handleOutgoingPacket(const uint8_t *packet, uint32_t length) = 0;

    void handleIncomingPacket(const uint8_t *packet, uint32_t length);

private:

    void freePacketBuffer(void *buffer);

    Util::Memory::String identifier;

    uint8_t *packetMemory;
    Kernel::BitmapMemoryManager packetMemoryManager;
    Util::Data::ArrayBlockingQueue<Packet> incomingPacketQueue;
    Util::Data::ArrayBlockingQueue<Packet> outgoingPacketQueue;
    Util::Async::Spinlock outgoingPacketLock;

    Util::Data::ArrayList<::Network::NetworkAddress*> addressList;
    Util::Async::ReentrantSpinlock addressLock;

    PacketReader *reader;
    PacketWriter *writer;

    Kernel::Logger log;

    static const constexpr uint32_t PACKET_BUFFER_SIZE = 2048;
    static const constexpr uint32_t MAX_BUFFERED_PACKETS = 16;
};

}

#endif