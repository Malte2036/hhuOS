//
// Created by Malte Sehmer on 01.01.23.
//

#include "Camera.h"

namespace Util::Game {

    Camera::Camera(const Vector2 &position) : position{position} {

    }

    Vector2 Camera::getPosition() {
        return position;
    }

    void Camera::setPosition(const Vector2 &vector2) {
        Camera::position = vector2;
    }
}
