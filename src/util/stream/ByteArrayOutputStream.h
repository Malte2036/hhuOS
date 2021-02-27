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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef HHUOS_BYTEARRAYOUTPUTSTREAM_H
#define HHUOS_BYTEARRAYOUTPUTSTREAM_H

#include <util/data/Array.h>
#include "OutputStream.h"

namespace Util::Stream {

class ByteArrayOutputStream : public OutputStream {

public:

    ByteArrayOutputStream();

    explicit ByteArrayOutputStream(uint32_t size);

    ByteArrayOutputStream(const ByteArrayOutputStream &copy) = delete;

    ByteArrayOutputStream &operator=(const ByteArrayOutputStream &copy) = delete;

    ~ByteArrayOutputStream() override;

    [[nodiscard]] uint32_t getSize() const;

    void getContent(uint8_t *target, uint32_t length) const;

    void reset();

    void write(uint8_t c) override;

    void write(const uint8_t *source, uint32_t offset, uint32_t length) override;

private:

    void ensureRemainingCapacity(uint32_t);

    uint8_t *buffer;
    uint32_t size;
    uint32_t position = 0;

    static const constexpr uint32_t DEFAULT_BUFFER_SIZE = 32;
};

}

#endif
