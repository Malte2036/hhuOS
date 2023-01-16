//
// Created by malte on 05.12.22.
//

#include "CollisionEvent.h"

#include <utility>

namespace Util::Game {
    CollisionEvent::CollisionEvent(Entity &other, Collision collision) : Event(), other{other}, collision{collision} {

    }

    Entity &CollisionEvent::getCollidedWith() {
        return other;
    }

    RectangleCollidedSide CollisionEvent::getRectangleCollidedSide() {
        return {};
    }

    Collision CollisionEvent::getCollision() {
        return collision;
    }
}
