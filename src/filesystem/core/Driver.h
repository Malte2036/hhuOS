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

#ifndef __FsDriver_include__
#define __FsDriver_include__

#include <lib/util/reflection/Prototype.h>
#include "Node.h"

namespace Filesystem {

/**
 * An interface between the Filesystem-class and a filesystem-driver.
 * Every filesystem-driver needs to implement the functions, that are specified by this class.
 * The Filesystem-class can then communicate with the respective driver.
 */
class Driver : public Util::Reflection::Prototype {

public:
    /**
     * Constructor.
     */
    Driver() = default;

    /**
     * Destructor.
     */
    ~Driver() override = default;

    /**
     * Mount a device.
     * After this function has succeeded, the driver must be ready to answer process requests for this device.
     *
     * @param device The device
     *
     * @return true, on success
     */
    virtual bool mount() = 0;

    /**
     * Get an FsNode, representing a file or directory that a given path points to.
     *
     * @param path The path.
     *
     * @return The FsNode (or nulltpr on failure)
     */
    virtual Node* getNode(const Util::Memory::String &path) = 0;

    /**
     * Create a new empty file or directory at a given path.
     * The parent-directory of the new file must exist beforehand.
     *
     * @param path The path
     *
     * @return true on success
     */
    virtual bool createNode(const Util::Memory::String &path) = 0;

    /**
     * Delete an existing file or directory at a given path.
     * The file must be a regular file or an empty folder (a leaf in the filesystem tree).
     *
     * @param path The path.
     *
     * @return true on success
     */
    virtual bool deleteNode(const Util::Memory::String &path) = 0;
};

}

#endif