//
// Created by Malte Sehmer on 05.12.22.
//

#include "RectangleCollider.h"
#include "lib/util/math/Math.h"


Util::Game::RectangleCollider::RectangleCollider(const Vector2 &position, double height, double width,
                                                 ColliderType colliderType) : Collider(
        "RectangleCollider", position, colliderType), height{height}, width{width} {}

Util::Game::RectangleCollidedSide Util::Game::RectangleCollider::isColliding(RectangleCollider &other) {
    if (getPosition().getX() < other.getPosition().getX() + other.getWidth() &&
        getPosition().getX() + getWidth() > other.getPosition().getX() &&
        getPosition().getY() < other.getPosition().getY() + other.getHeight() &&
        getHeight() + getPosition().getY() > other.getPosition().getY()) {

        auto lastCenter = lastPosition + Vector2(getWidth() / 2, getHeight() / 2);
        auto otherLastCenter = other.lastPosition + Vector2(other.getWidth() / 2, other.getHeight() / 2);

        auto centerXDistance = lastCenter.getX() - otherLastCenter.getX();
        auto centerYDistance = lastCenter.getY() - otherLastCenter.getY();

        auto absoluteXDistance = getWidth() / 2 + other.getWidth() / 2 - Math::Math::absolute(centerXDistance);
        auto absoluteYDistance = getHeight() / 2 + other.getHeight() / 2 - Math::Math::absolute(centerYDistance);

        if (absoluteXDistance >= absoluteYDistance) {
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

double Util::Game::RectangleCollider::getHeight() {
    return height;
}

double Util::Game::RectangleCollider::getWidth() {
    return width;
}

void Util::Game::RectangleCollider::setHeight(double val) {
    height = val;
}

void Util::Game::RectangleCollider::setWidth(double val) {
    width = val;
}
