//
// Created by malte on 05.12.22.
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
        explicit RectangleCollider(Vector2 position, double height, double width, ColliderType colliderType);

        double getHeight();

        double getWidth();

        void setHeight(double val);

        void setWidth(double val);

    protected:
        RectangleCollidedSide isColliding(RectangleCollider other);

    private:
        double height, width;
    };
}


#endif //HHUOS_RECTANGLECOLLIDER_H
