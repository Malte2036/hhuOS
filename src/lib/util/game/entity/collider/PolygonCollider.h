//
// Created by Malte Sehmer on 10.01.23.
//

#ifndef HHUOS_POLYGONCOLLIDER_H
#define HHUOS_POLYGONCOLLIDER_H

#include "lib/util/game/entity/collider/Collider.h"
#include "lib/util/data/Pair.h"
#include "lib/util/game/Polygon.h"

namespace Util::Game {

    struct Collision {
        double overlap;
        Vector2 axis;
    };

    class PolygonCollider : Collider {
        friend class Scene;

    public:
        explicit PolygonCollider(Polygon &polygon, ColliderType colliderType = DYNAMIC_COLLIDER);

        /**
         * Copy Constructor.
        */
        PolygonCollider(const PolygonCollider &other) = default;

        /**
         * Assignment operator.
         */
        PolygonCollider &operator=(const PolygonCollider &other) = delete;

        Collision isColliding(PolygonCollider &other);

        Polygon &getPolygon();

    private:
        static Data::Pair<double, double>
        projectPolygonOnAxis(Util::Data::Array<Vector2> vertices, const Vector2 &axis);

        Polygon &polygon;

        static Vector2 getAxes(Data::Array<Vector2> vertices, int index);

        static double getOverlap(Data::Pair<double, double> range, Data::Pair<double, double> rangeOther);
    };
}


#endif //HHUOS_POLYGONCOLLIDER_H