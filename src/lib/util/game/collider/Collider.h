//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_COLLIDER_H
#define HHUOS_COLLIDER_H

#include "lib/util/memory/String.h"
#include "lib/util/math/Vector2.h"

namespace Util::Game {
    class Collider {
    public:
        Collider(Memory::String type, Vector2 position);

        Memory::String getType();

        Vector2 getPosition();

        // RectangleCollider needs to be replaced
        //virtual bool isColliding(Collider other) = 0;
    private:
        Memory::String type;
        Vector2 position;
    };
}


#endif //HHUOS_COLLIDER_H
