//
// Created by malte on 05.12.22.
//

#include "Collider.h"


Util::Game::Collider::Collider(Util::Memory::String type, Vector2 position) : type{type}, position{position} {}

Vector2 Util::Game::Collider::getPosition() {
    return position;
}

Util::Memory::String Util::Game::Collider::getType() {
    return type;
}
