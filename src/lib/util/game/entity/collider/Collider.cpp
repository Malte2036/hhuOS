//
// Created by Malte Sehmer on 05.12.22.
//

#include "Collider.h"


Util::Game::Collider::Collider(const Util::Memory::String &type, const Vector2 &position, ColliderType colliderType)
        : lastPosition{position}, type{type}, position{position}, colliderType{colliderType} {}

Vector2 Util::Game::Collider::getPosition() {
    return position;
}

Util::Memory::String Util::Game::Collider::getType() {
    return type;
}

Util::Game::ColliderType Util::Game::Collider::getColliderType() {
    return colliderType;
}

Vector2 Util::Game::Collider::setPosition(const Vector2& vector2) {
    position = vector2;
}
