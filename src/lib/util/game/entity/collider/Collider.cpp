//
// Created by malte on 05.12.22.
//

#include "Collider.h"


Util::Game::Collider::Collider(const Util::Memory::String& type, const Vector2& position, ColliderType colliderType) : type{type},
                                                                                                         position{
                                                                                                                 position},
                                                                                                         colliderType{
                                                                                                                 colliderType} {}

Vector2 Util::Game::Collider::getPosition() {
    return position;
}

Util::Memory::String Util::Game::Collider::getType() {
    return type;
}

Util::Game::ColliderType Util::Game::Collider::getColliderType() {
    return colliderType;
}
