//
// Created by malte on 05.12.22.
//

#include "TransformEvent.h"

namespace Util::Game {
    TransformEvent::TransformEvent(Vector2 transformTo) : transformTo{transformTo} {}

    Vector2 TransformEvent::getTransformTo() {
        return transformTo;
    }
}
