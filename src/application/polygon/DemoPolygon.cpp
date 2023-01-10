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

#include "DemoPolygon.h"

DemoPolygon::DemoPolygon() : Util::Game::Polygon(Util::Data::Array<Vector2>(0)), color(0, 0, 0), rotationSpeed(0),
                             scaleSpeed(0) {}

DemoPolygon::DemoPolygon(const Util::Data::Array<Vector2> &vertices, const Util::Graphic::Color &color,
                         double rotationSpeed, double scaleSpeed) : Util::Game::Polygon(vertices), color(color),
                                                                    rotationSpeed(rotationSpeed),
                                                                    scaleSpeed(scaleSpeed) {}

void DemoPolygon::update(double delta) {
    const double rotationAngle = delta * rotationSpeed;
    const double scaleFactor = scaleUp ? 1 + (delta * scaleSpeed) : 1 - (delta * scaleSpeed);
    currentScale *= scaleFactor;
    if (currentScale >= 2) {
        scaleUp = false;
    } else if (currentScale <= 0.5) {
        scaleUp = true;
    }

    rotate(rotationAngle);
    scale(scaleFactor);
}

void DemoPolygon::draw(Util::Game::Graphics2D &graphics) const {
    graphics.setColor(color);
    Polygon::draw(graphics);
}
