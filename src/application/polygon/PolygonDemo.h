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

#ifndef HHUOS_POLYGONDEMO_H
#define HHUOS_POLYGONDEMO_H

#include "lib/util/game/Game.h"
#include "lib/util/data/ArrayListBlockingQueue.h"
#include "DemoPolygon.h"
#include "DemoPolygonFactory.h"

class PolygonDemo : public Util::Game::Game, public Util::Game::KeyListener {

public:
    /**
     * Default Constructor.
     */
    explicit PolygonDemo(uint32_t count);

    /**
     * Copy Constructor.
     */
    PolygonDemo(const PolygonDemo &other) = delete;

    /**
     * Assignment operator.
     */
    PolygonDemo &operator=(const PolygonDemo &other) = delete;

    /**
     * Destructor.
     */
    ~PolygonDemo() override = default;

    void update(double delta) override;

    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;

    void keyPressed(char c) override;

private:

    DemoPolygonFactory factory;
    Util::Data::ArrayListBlockingQueue<DemoPolygon*> polygons;
};

#endif