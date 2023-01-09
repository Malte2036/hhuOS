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

#ifndef HHUOS_CUBEDEMO_H
#define HHUOS_CUBEDEMO_H

#include "lib/util/game/Game.h"

class CubeDemo : public Util::Game::Game {

public:
    /**
     * Constructor.
     */
    explicit CubeDemo() = default;

    /**
     * Copy Constructor.
     */
    CubeDemo(const CubeDemo &other) = delete;

    /**
     * Assignment operator.
     */
    CubeDemo &operator=(const CubeDemo &other) = delete;

    /**
     * Destructor.
     */
    ~CubeDemo() override = default;

    void update(double dt) override;
};

#endif
