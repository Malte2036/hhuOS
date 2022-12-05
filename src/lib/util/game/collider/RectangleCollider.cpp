//
// Created by malte on 05.12.22.
//

#include "RectangleCollider.h"


Util::Game::RectangleCollider::RectangleCollider(double height, double width) : height{height}, width{width} {}


bool Util::Game::RectangleCollider::isColliding(Util::Game::Collider &other) {
    return false;
}
