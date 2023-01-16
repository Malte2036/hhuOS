//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_COLLISIONEVENT_H
#define HHUOS_COLLISIONEVENT_H

#include "Event.h"
#include "lib/util/memory/String.h"
#include "lib/util/game/entity/collider/RectangleCollider.h"
#include "lib/util/game/entity/collider/PolygonCollider.h"


namespace Util::Game {
    class Entity;

    class CollisionEvent : public Event {
    public:
        explicit CollisionEvent(Entity &other, Collision collision);

        /**
         * Copy Constructor.
        */
        CollisionEvent(const CollisionEvent &other) = delete;

        /**
         * Assignment operator.
         */
        CollisionEvent &operator=(const CollisionEvent &other) = delete;

        Entity &getCollidedWith();

        [[deprecated("use getCollision() instead")]]
        RectangleCollidedSide getRectangleCollidedSide();

        Collision getCollision();

    private:
        Memory::String type = "CollisionEvent";

        Entity &other;
        const Collision collision;
    };
}


#endif //HHUOS_COLLISIONEVENT_H
