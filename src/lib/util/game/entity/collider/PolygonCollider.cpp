//
// Created by malte on 10.01.23.
//

#include "PolygonCollider.h"
#include "lib/util/math/Math.h"

namespace Util::Game {
    PolygonCollider::PolygonCollider(Util::Data::Array<Vector2> &vertices, ColliderType colliderType)
            : Util::Game::Collider("PolygonCollider", Vector2(), colliderType), vertices{vertices} {

    }

    bool PolygonCollider::isColliding(PolygonCollider other) {
        for (auto i = 0; i < vertices.length(); i++) {
            auto axis = getAxes(vertices, i);

            auto range = projectPolygonOnAxis(vertices, axis);
            auto rangeOther = projectPolygonOnAxis(other.vertices, axis);

            auto vOffset = Vector2(getPosition().getX() - other.getPosition().getX(),
                                   getPosition().getY() - other.getPosition().getY());

            auto scalerOffset = axis.dotProduct(vOffset);
            range.first += scalerOffset;
            range.second += scalerOffset;

            if ((range.first - rangeOther.second > 0) || (rangeOther.first - range.second > 0)) {
                return false;
            }
        }

        return true;
    }

    Vector2 PolygonCollider::getAxes(Data::Array<Vector2> &vertices, int index) {
        auto pt1 = vertices[index];
        auto pt2 = index >= vertices.length() - 1 ? vertices[0] : vertices[index + 1];
        auto axis = Vector2(-(pt2.getY() - pt1.getY()), pt2.getX() - pt1.getX());
        return axis.normalize();
    }

    Data::Pair<double, double>
    PolygonCollider::projectPolygonOnAxis(Data::Array<Vector2> &vertices, const Vector2 &axis) {
        double pMin = axis.dotProduct(vertices[0]);
        double pMax = -10000;

        for (auto &vertex: vertices) {
            auto dot = axis.dotProduct(vertex);
            pMin = Math::Math::min(pMin, dot);
            pMax = Math::Math::max(pMax, dot);
        }
        return {pMin, pMax};
    }
}