//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_COLLISIONEVENT_H
#define HHUOS_COLLISIONEVENT_H

#include "Event.h"
#include "lib/util/memory/String.h"
#include "lib/util/math/Vector2.h"
#include "lib/util/game/collider/RectangleCollider.h"


namespace Util::Game {
    class CollisionEvent : public Event {
    public:
        CollisionEvent() = default;

    private:
        Memory::String type = "CollisionEvent";
    };
}


#endif //HHUOS_COLLISIONEVENT_H
