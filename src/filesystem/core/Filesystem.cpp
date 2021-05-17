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

#include "Filesystem.h"

namespace Filesystem {

Util::Memory::String Filesystem::parsePath(const Util::Memory::String &path) {
    Util::Data::Array<Util::Memory::String> token = path.split(Filesystem::SEPARATOR);
    Util::Data::ArrayList<Util::Memory::String> parsedToken;

    for (const Util::Memory::String &string : token) {
        if (string == ".") {
            continue;
        } else if (string == "..") {
            if (!parsedToken.isEmpty()) {
                parsedToken.remove(parsedToken.size() - 1);
            }
        } else {
            parsedToken.add(*new Util::Memory::String(string));
        }
    }

    if (parsedToken.isEmpty()) {
        return "";
    }

    Util::Memory::String parsedPath = Filesystem::SEPARATOR + Util::Memory::String::join(Filesystem::SEPARATOR, parsedToken.toArray());
    return parsedPath;
}

Driver* Filesystem::getMountedDriver(Util::Memory::String &path) {
    if (!path.endsWith(Filesystem::SEPARATOR)) {
        path += Filesystem::SEPARATOR;
    }

    Util::Memory::String ret;

    for (const Util::Memory::String &currentString: mountPoints.keySet()) {
        if (path.beginsWith(currentString)) {
            if (currentString.length() > ret.length()) {
                ret = currentString;
            }
        }
    }

    if (ret.isEmpty()) {
        return nullptr;
    }

    path = path.substring(ret.length(), path.length() - 1);
    return mountPoints.get(ret);
}

void Filesystem::init() {
    for (const Util::Memory::String &path : mountPoints.keySet()) {
        delete mountPoints.get(path);
    }

    mountPoints.clear();
}

Node* Filesystem::getNode(const Util::Memory::String &path) {
    Util::Memory::String parsedPath = parsePath(path);
    lock.acquire();

    Driver *driver = getMountedDriver(parsedPath);
    if (driver == nullptr) {
        return lock.releaseAndReturn(nullptr);
    }

    Node *ret = driver->getNode(parsedPath);
    return lock.releaseAndReturn(ret);
}

bool Filesystem::createFile(const Util::Memory::String &path) {
    Util::Memory::String parsedPath = parsePath(path);
    lock.acquire();

    Driver *driver = getMountedDriver(parsedPath);
    if (driver == nullptr) {
        return lock.releaseAndReturn(false);
    }

    bool ret = driver->createNode(parsedPath);
    return lock.releaseAndReturn(ret);
}

bool Filesystem::createDirectory(const Util::Memory::String &path) {
    Util::Memory::String parsedPath = parsePath(path);
    lock.acquire();

    Driver *driver = getMountedDriver(parsedPath);

    if (driver == nullptr) {
        return lock.releaseAndReturn(false);
    }

    bool ret = driver->createNode(parsedPath);
    return lock.releaseAndReturn(ret);
}

bool Filesystem::deleteFile(const Util::Memory::String &path) {
    Util::Memory::String parsedPath = parsePath(path);
    lock.acquire();

    for (const Util::Memory::String &key : mountPoints.keySet()) {
        if (key.beginsWith(parsedPath)) {
            lock.release();
            return false;
        }
    }

    Driver *driver = getMountedDriver(parsedPath);
    if (driver == nullptr) {
        return lock.releaseAndReturn(false);
    }

    bool ret = driver->deleteNode(parsedPath);
    return lock.releaseAndReturn<bool>(ret);
}

}