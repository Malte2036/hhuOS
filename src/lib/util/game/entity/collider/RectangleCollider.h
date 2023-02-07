//
// Created by Malte Sehmer on 05.12.22.
//

#ifndef HHUOS_RECTANGLECOLLIDER_H
#define HHUOS_RECTANGLECOLLIDER_H

#include "Collider.h"

namespace Util::Game {
    enum RectangleCollidedSide {
        LEFT_SIDE, RIGHT_SIDE, TOP_SIDE, BOTTOM_SIDE, NO_SIDE
    };

    class RectangleCollider : public Collider {
        friend class Scene;

    public:
        explicit RectangleCollider(const Vector2 &position, double height, double width, ColliderType colliderType);

        /**
         * Copy Constructor.
        */
        RectangleCollider(const RectangleCollider &other) = delete;

        /**
         * Assignment operator.
         */
        RectangleCollider &operator=(const RectangleCollider &other) = delete;

        double getHeight();

        double getWidth();

        void setHeight(double val);

        void setWidth(double val);

    protected:
        RectangleCollidedSide isColliding(RectangleCollider &other);

    private:
        double height, width;
    };
}


#endif //HHUOS_RECTANGLECOLLIDER_H
