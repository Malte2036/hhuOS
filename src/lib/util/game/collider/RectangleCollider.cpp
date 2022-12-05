//
// Created by malte on 05.12.22.
//

#include "RectangleCollider.h"


Util::Game::RectangleCollider::RectangleCollider(Vector2 position, double height, double width) : Collider(
        "RectangleCollider", position), height{height}, width{width} {}

double Util::Game::RectangleCollider::getHeight() {
    return height;
}

double Util::Game::RectangleCollider::getWidth() {
    return width;
}

bool Util::Game::RectangleCollider::isColliding(RectangleCollider other) {
    if (getPosition().getX() < other.getPosition().getX() + other.getWidth() &&
        getPosition().getX() + getWidth() > other.getPosition().getX() &&
        getPosition().getY() < other.getPosition().getY() + other.getHeight() &&
        getHeight() + getPosition().getY() > other.getPosition().getY()) {
        return true;
    }
    return false;
}