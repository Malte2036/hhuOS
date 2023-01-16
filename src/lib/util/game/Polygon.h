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

#ifndef HHUOS_POLYGON_H
#define HHUOS_POLYGON_H

#include "lib/util/data/Array.h"
#include "Drawable.h"

namespace Util::Game {

class Polygon : public Drawable {

public:
    /**
     * Constructor.
     */
    explicit Polygon(const Data::Array<Vector2>& vertices);

    /**
     * Copy Constructor.
     */
    Polygon(const Polygon &other) = default;

    /**
     * Assignment operator.
     */
    Polygon &operator=(const Polygon &other) = default;

    /**
     * Destructor.
     */
    ~Polygon() override = default;

    void scale(double factor);

    void rotate(double angle);

    void translate(const Vector2& translation);

    void draw(Graphics2D &graphics) const override;

    Vector2 getCenter();

    Data::Array<Vector2> getVertices();

    void setPosition(const Vector2 &newPosition);

private:

    void calculateCenter();

    Data::Array<Vector2> vertices;
    Vector2 center;

};

}

#endif
