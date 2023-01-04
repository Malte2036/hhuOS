//
// Created by malte on 05.12.22.
//

#include "CollisionEvent.h"

namespace Util::Game {
    CollisionEvent::CollisionEvent(Entity *other, RectangleCollidedSide rectangleCollidedSide)
            : Event(), other{other}, rectangleCollidedSide{rectangleCollidedSide} {

    }

    Entity *CollisionEvent::getCollidedWith() {
        return other;
    }

    RectangleCollidedSide CollisionEvent::getRectangleCollidedSide() {
        return rectangleCollidedSide;
    }

}
