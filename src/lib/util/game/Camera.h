//
// Created by Malte Sehmer on 01.01.23.
//

#ifndef HHUOS_CAMERA_H
#define HHUOS_CAMERA_H


#include "lib/util/math/Vector2.h"

namespace Util::Game {
    class Camera {
    public:
        explicit Camera(const Vector2 &position);

        /**
        * Copy Constructor.
        */
        Camera(const Camera &other) = delete;

        /**
         * Assignment operator.
         */
        Camera &operator=(const Camera &other) = delete;

        Vector2 getPosition();

        void setPosition(const Vector2 &vector2);

    private:
        Vector2 position;
    };
}


#endif //HHUOS_CAMERA_H
