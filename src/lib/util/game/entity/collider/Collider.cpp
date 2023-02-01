//
// Created by Malte Sehmer on 05.12.22.
//

#include "Collider.h"

namespace Util::Game {
    Collider::Collider(const Util::Memory::String &type, const Vector2 &position, ColliderType colliderType)
            : lastPosition{position}, type{type}, position{position}, colliderType{colliderType} {}

    Vector2 Collider::getPosition() {
        return position;
    }

    Util::Memory::String Collider::getType() {
        return type;
    }

    ColliderType Collider::getColliderType() {
        return colliderType;
    }

    Vector2 Collider::setPosition(const Vector2 &vector2) {
        position = vector2;
    }
}