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

#include "Polygon.h"
#include "lib/util/math/Math.h"

namespace Util::Game {

    Polygon::Polygon(const Data::Array<Vector2> &vertices) : vertices{vertices} {
        calculateCenter();
    }

    void Polygon::draw(Graphics2D &graphics) const {
        graphics.drawPolygon(vertices);
    }

    void Polygon::scale(double factor) {
        for (auto &vertex: vertices) {
            vertex = Vector2(center.getX() + factor * (vertex.getX() - center.getX()),
                             center.getY() + factor * (vertex.getY() - center.getY()));
        }
    }

    void Polygon::rotate(double angle) {
        double sine = Math::Math::sine(angle);
        double cosine = Math::Math::cosine(angle);

        for (auto &vertex: vertices) {
            auto d = vertex - center;
            vertex = Vector2(d.getX() * cosine - d.getY() * sine + center.getX(),
                             d.getX() * sine + d.getY() * cosine + center.getY());
        }

    }

    void Polygon::translate(const Vector2 &translation) {
        for (auto &vertex: vertices) {
            vertex = vertex + translation;
        }
        center = center + translation;
    }

    void Polygon::calculateCenter() {
        Vector2 temp = Vector2();
        for (auto &vertex: vertices) {
            temp = temp + vertex;
        }

        center = temp / (int) vertices.length();
    }

    void Polygon::setPosition(const Vector2 &newPosition) {
        auto translation = newPosition - center;
        translate(translation);
    }

    Vector2 Polygon::getCenter() {
        return center;
    }

    Data::Array<Vector2> Polygon::getVertices() {
        return vertices;
    }

}