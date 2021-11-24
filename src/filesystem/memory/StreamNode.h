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

#ifndef HHUOS_STREAMNODE_H
#define HHUOS_STREAMNODE_H

#include <lib/util/stream/OutputStream.h>
#include <lib/util/stream/InputStream.h>
#include "MemoryNode.h"

namespace Filesystem::Memory {

class StreamNode : public MemoryNode {

public:
    /**
     * Constructor.
     */
     StreamNode(const Util::Memory::String &name, Util::Stream::OutputStream *outputStream, Util::Stream::InputStream *inputStream);

    /**
     * Constructor.
     */
    StreamNode(const Util::Memory::String &name, Util::Stream::OutputStream *outputStream);

    /**
     * Constructor.
     */
    StreamNode(const Util::Memory::String &name, Util::Stream::InputStream *inputStream);

    /**
     * Copy-constructor.
     */
    StreamNode(const StreamNode &copy) = delete;

    /**
     * Assignment operator.
     */
    StreamNode& operator=(const StreamNode &other) = delete;

    /**
     * Destructor.
     */
    ~StreamNode() override;

    /**
     * Overriding function from Node.
     */
    Util::File::Type getFileType() override;

    /**
     * Overriding function from Node.
     */
    uint64_t readData(uint8_t *targetBuffer, uint64_t pos, uint64_t numBytes) override;

    /**
     * Overriding function from Node.
     */
    uint64_t writeData(const uint8_t *sourceBuffer, uint64_t pos, uint64_t numBytes) override;

private:

    Util::Stream::OutputStream *outputStream;
    Util::Stream::InputStream *inputStream;

};

}

#endif