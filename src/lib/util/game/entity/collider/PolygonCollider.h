//
// Created by malte on 10.01.23.
//

#ifndef HHUOS_POLYGONCOLLIDER_H
#define HHUOS_POLYGONCOLLIDER_H

#include "lib/util/game/entity/collider/Collider.h"
#include "lib/util/data/Pair.h"

namespace Util::Game {
    class PolygonCollider : Collider {
        friend class Scene;

    public:
        explicit PolygonCollider(Util::Data::Array<Vector2> &vertices, ColliderType colliderType = DYNAMIC_COLLIDER);

        /**
         * Copy Constructor.
        */
        PolygonCollider(const PolygonCollider &other) = default;

        /**
         * Assignment operator.
         */
        PolygonCollider &operator=(const PolygonCollider &other) = delete;

        bool isColliding(PolygonCollider other);

    private:
        static Data::Pair<double, double>
        projectPolygonOnAxis(Util::Data::Array<Vector2> &vertices, const Vector2 &axis);

        Util::Data::Array<Vector2> &vertices;

        static Vector2 getAxes(Data::Array <Vector2> &vertices, int index);
    };
}


#endif //HHUOS_POLYGONCOLLIDER_H
