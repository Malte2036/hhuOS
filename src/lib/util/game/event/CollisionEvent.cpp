//
// Created by malte on 05.12.22.
//

#include "CollisionEvent.h"

namespace Util::Game {
    CollisionEvent::CollisionEvent(const Memory::String &collidedWithTag) : collidedWithTag{collidedWithTag} {}

    Memory::String CollisionEvent::getCollidedWithTag() {
        return collidedWithTag;
    }
}
