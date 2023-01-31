//
// Created by Malte Sehmer on 05.12.22.
//

#ifndef HHUOS_COLLISIONEVENT_H
#define HHUOS_COLLISIONEVENT_H

#include "Event.h"
#include "lib/util/memory/String.h"
#include "lib/util/game/entity/collider/RectangleCollider.h"


namespace Util::Game {
    class Entity;

    class CollisionEvent : public Event {
    public:
        explicit CollisionEvent(Entity &other, RectangleCollidedSide rectangleCollidedSide);

        /**
         * Copy Constructor.
        */
        CollisionEvent(const CollisionEvent &other) = delete;

        /**
         * Assignment operator.
         */
        CollisionEvent &operator=(const CollisionEvent &other) = delete;

        Entity &getCollidedWith();
        RectangleCollidedSide getRectangleCollidedSide();

    private:
        Memory::String type = "CollisionEvent";

        Entity &other;
        const RectangleCollidedSide rectangleCollidedSide;
    };
}


#endif //HHUOS_COLLISIONEVENT_H
