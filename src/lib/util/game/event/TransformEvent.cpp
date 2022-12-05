//
// Created by malte on 05.12.22.
//

#include "TransformEvent.h"

Util::Game::TransformEvent::TransformEvent(Vector2 transformTo) : transformTo{transformTo} {}

Vector2 Util::Game::TransformEvent::getTransformTo() {
    return transformTo;
}
