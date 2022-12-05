//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_COLLIDER_H
#define HHUOS_COLLIDER_H

namespace Util::Game {
    class Collider {
        virtual bool isColliding(Collider &other) = 0;
    };
}


#endif //HHUOS_COLLIDER_H
