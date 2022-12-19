//
// Created by malte on 05.12.22.
//

#include "CollisionEvent.h"

namespace Util::Game {
    CollisionEvent::CollisionEvent(Entity *other) : Event(), other{other} {

    }

    const Entity *CollisionEvent::getCollidedWith() {
        return other;
    }

}
