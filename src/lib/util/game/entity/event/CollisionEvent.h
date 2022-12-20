//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_COLLISIONEVENT_H
#define HHUOS_COLLISIONEVENT_H

#include "Event.h"
#include "lib/util/memory/String.h"


namespace Util::Game {
    class Entity;

    class CollisionEvent : public Event {
    public:
        explicit CollisionEvent(Entity *other);

        const Entity *getCollidedWith();

    private:
        Memory::String type = "CollisionEvent";

        const Entity *other;
    };
}


#endif //HHUOS_COLLISIONEVENT_H
