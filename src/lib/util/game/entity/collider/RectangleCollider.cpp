//
// Created by Malte Sehmer on 05.12.22.
//

#include "RectangleCollider.h"
#include "lib/util/math/Math.h"


Util::Game::RectangleCollider::RectangleCollider(Vector2 position, double height, double width,
                                                 ColliderType colliderType) : Collider(
        "RectangleCollider", position, colliderType), height{height}, width{width} {}

double Util::Game::RectangleCollider::getHeight() {
    return height;
}

double Util::Game::RectangleCollider::getWidth() {
    return width;
}

Util::Game::RectangleCollidedSide Util::Game::RectangleCollider::isColliding(RectangleCollider other) {
    if (getPosition().getX() < other.getPosition().getX() + other.getWidth() &&
        getPosition().getX() + getWidth() > other.getPosition().getX() &&
        getPosition().getY() < other.getPosition().getY() + other.getHeight() &&
        getHeight() + getPosition().getY() > other.getPosition().getY()) {

        auto lastCenter = lastPosition + Vector2(getWidth() / 2, getHeight() / 2);
        auto otherLastCenter = other.lastPosition + Vector2(other.getWidth() / 2, other.getHeight() / 2);

        auto centerXDistance = lastCenter.getX() - otherLastCenter.getX();
        auto centerYDistance = lastCenter.getY() - otherLastCenter.getY();

        if (Math::Math::absolute(centerXDistance) < Math::Math::absolute(centerYDistance)) {
            if (centerYDistance < 0) {
                return TOP_SIDE;
            }
            return BOTTOM_SIDE;
        }

        if (centerXDistance > 0) {
            return LEFT_SIDE;
        }
        return RIGHT_SIDE;
    }
    return NO_SIDE;
}

void Util::Game::RectangleCollider::setHeight(double val) {
    height = val;
}

void Util::Game::RectangleCollider::setWidth(double val) {
    width = val;
}
