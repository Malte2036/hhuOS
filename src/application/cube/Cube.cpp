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

#include "Cube.h"
#include "lib/util/math/Math.h"
#include "lib/util/graphic/LineDrawer.h"

const Util::Graphic::Color Cube::color = Util::Graphic::Color(10,255,0);

Cube::Cube(double x, double y, double size) : x(x), y(y), size(size) {
    //       7 - - - - - 6
    //     / |         / |
    //    4 - - - - - 5  |
    //    |  |        |  |
    //    |  3 - - - -|- 2
    //    | /         | /
    //    0 - - - - - 1
    coordinates[0][indX] = x - size; coordinates[0][indY] = y - size; coordinates[0][indZ] = -size;
    coordinates[1][indX] = x + size; coordinates[1][indY] = y - size; coordinates[1][indZ] = -size;
    coordinates[2][indX] = x + size; coordinates[2][indY] = y - size; coordinates[2][indZ] = +size;
    coordinates[3][indX] = x - size; coordinates[3][indY] = y - size; coordinates[3][indZ] = +size;
    coordinates[4][indX] = x - size; coordinates[4][indY] = y + size; coordinates[4][indZ] = -size;
    coordinates[5][indX] = x + size; coordinates[5][indY] = y + size; coordinates[5][indZ] = -size;
    coordinates[6][indX] = x + size; coordinates[6][indY] = y + size; coordinates[6][indZ] = +size;
    coordinates[7][indX] = x - size; coordinates[7][indY] = y + size; coordinates[7][indZ] = +size;
}

void Cube::draw(Util::Game::Graphics2D &graphics) const {
    graphics.setColor(color);
    graphics.drawLine(Vector2(coordinates[0][indX], coordinates[0][indY]), Vector2(coordinates[1][indX], coordinates[1][indY]));
    graphics.drawLine(Vector2(coordinates[1][indX], coordinates[1][indY]), Vector2(coordinates[2][indX], coordinates[2][indY]));
    graphics.drawLine(Vector2(coordinates[2][indX], coordinates[2][indY]), Vector2(coordinates[3][indX], coordinates[3][indY]));
    graphics.drawLine(Vector2(coordinates[3][indX], coordinates[3][indY]), Vector2(coordinates[0][indX], coordinates[0][indY]));
    graphics.drawLine(Vector2(coordinates[4][indX], coordinates[4][indY]), Vector2(coordinates[5][indX], coordinates[5][indY]));
    graphics.drawLine(Vector2(coordinates[5][indX], coordinates[5][indY]), Vector2(coordinates[6][indX], coordinates[6][indY]));
    graphics.drawLine(Vector2(coordinates[6][indX], coordinates[6][indY]), Vector2(coordinates[7][indX], coordinates[7][indY]));
    graphics.drawLine(Vector2(coordinates[7][indX], coordinates[7][indY]), Vector2(coordinates[4][indX], coordinates[4][indY]));
    graphics.drawLine(Vector2(coordinates[0][indX], coordinates[0][indY]), Vector2(coordinates[4][indX], coordinates[4][indY]));
    graphics.drawLine(Vector2(coordinates[1][indX], coordinates[1][indY]), Vector2(coordinates[5][indX], coordinates[5][indY]));
    graphics.drawLine(Vector2(coordinates[2][indX], coordinates[2][indY]), Vector2(coordinates[6][indX], coordinates[6][indY]));
    graphics.drawLine(Vector2(coordinates[3][indX], coordinates[3][indY]), Vector2(coordinates[7][indX], coordinates[7][indY]));
}

void Cube::rotate(double angleX, double angleY, double angleZ) {
    const double cosineX = Util::Math::Math::cosine(angleX);
    const double cosineY = Util::Math::Math::cosine(angleY);
    const double cosineZ = Util::Math::Math::cosine(angleZ);
    const double sineX = Util::Math::Math::sine(angleX);
    const double sineY = Util::Math::Math::sine(angleY);
    const double sineZ = Util::Math::Math::sine(angleZ);
    double px, py, pz;

    // Rotate coordinates and recalculate corner points
    for (auto &corner : coordinates) {
        px = corner[indX];
        py = corner[indY];
        pz = corner[indZ];

        // Rotate around x-axis
        corner[indY] = py * cosineX - pz * sineX;
        corner[indZ] = py * sineX + pz * cosineX;

        py = corner[indY];
        pz = corner[indZ];

        // Rotate around y-axis
        corner[indX] = px * cosineY + pz * sineY;
        corner[indZ] = -px * sineY + pz * cosineY;

        px = corner[indX];

        // Rotate around z-axis
        corner[indX] = px * cosineZ - py * sineZ;
        corner[indY] = py * cosineZ + px * sineZ;
    }
}
