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

#ifndef HHUOS_DEMOPOLYGONFACTORY_H
#define HHUOS_DEMOPOLYGONFACTORY_H

#include "DemoPolygon.h"
#include "lib/util/math/Random.h"

class DemoPolygonFactory {

public:
    /**
     * Constructor.
     */
    DemoPolygonFactory() = default;

    /**
     * Copy Constructor.
     */
    DemoPolygonFactory(const DemoPolygonFactory &other) = delete;

    /**
     * Assignment operator.
     */
    DemoPolygonFactory &operator=(const DemoPolygonFactory &other) = delete;

    /**
     * Destructor.
     */
    ~DemoPolygonFactory() = default;

    DemoPolygon* createPolygon();

private:

    Util::Math::Random random = Util::Math::Random(256);

    static const Util::Data::Array<Vector2> shape1;
    static const Util::Data::Array<Vector2> shape2;
    static const Util::Data::Array<Vector2> shape3;
    static const Util::Data::Array<Vector2> shape4;
    static const Util::Data::Array<Vector2> shape5;

    static const Util::Data::Array<const Util::Data::Array<Vector2>*> shapes;
};

#endif