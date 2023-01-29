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

#ifndef HHUOS_DEMOPOLYGON_H
#define HHUOS_DEMOPOLYGON_H

#include "lib/util/game/Polygon.h"

class DemoPolygon : public Util::Game::Polygon {

public:
    /**
     * Default Constructor.
     */
    DemoPolygon();

    /**
     * Constructor.
     */
    DemoPolygon(const Util::Data::Array<Vector2> &vertices, const Util::Graphic::Color &color, double rotationSpeed, double scaleSpeed);

    /**
     * Copy Constructor.
     */
    DemoPolygon(const DemoPolygon &other) = default;

    /**
     * Assignment operator.
     */
    DemoPolygon &operator=(const DemoPolygon &other) = default;

    /**
     * Destructor.
     */
    ~DemoPolygon() override = default;

    void update(double delta);

    void draw(Util::Game::Graphics2D &graphics) const override;

private:

    Util::Graphic::Color color;
    double rotationSpeed;
    double scaleSpeed;
    double currentScale = 1;
    bool scaleUp = true;
};

#endif