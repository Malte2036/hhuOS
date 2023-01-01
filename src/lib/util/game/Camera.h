//
// Created by malte on 01.01.23.
//

#ifndef HHUOS_CAMERA_H
#define HHUOS_CAMERA_H


#include "lib/util/math/Vector2.h"

namespace Util::Game {
    class Camera {
    public:
        Camera(const Vector2& position);

        Vector2 getPosition();
        void setPosition(Vector2 position);

    private:
        Vector2 position;
    };
}


#endif //HHUOS_CAMERA_H
