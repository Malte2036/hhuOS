//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_COLLIDER_H
#define HHUOS_COLLIDER_H

#include "lib/util/memory/String.h"
#include "lib/util/math/Vector2.h"

namespace Util::Game {
    enum ColliderType {
        DYNAMIC_COLLIDER, STATIC_COLLIDER
    };

    class Collider {
    public:
        Collider(const Memory::String& type, const Vector2& position, ColliderType colliderType);

        Memory::String getType();

        Vector2 getPosition();

        ColliderType getColliderType();
    private:
        Memory::String type;
        Vector2 position;
        const ColliderType colliderType;
    };
}


#endif //HHUOS_COLLIDER_H
