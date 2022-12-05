//
// Created by malte on 05.12.22.
//

#include "SnakeEntity.h"

SnakeEntity::SnakeEntity(const Vector2 &position, double size, Util::Graphic::Color color, DirectionType direction,
                         double speed)
        : Util::Game::Entity(position, size), color{color}, direction{direction}, speed{speed} {}


void SnakeEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.setColor(color);
    graphics.drawRectangle(getPosition(), getSize());
}


DirectionType SnakeEntity::getDirection() {
    return direction;
}

void SnakeEntity::setDirection(DirectionType directionType) {
    direction = directionType;
}

void SnakeEntity::setColor(Util::Graphic::Color value) {
    color = value;
}

Util::Game::RectangleCollider SnakeEntity::getCollider() const {
    return Util::Game::RectangleCollider(getSize(), getSize());
}

void SnakeEntity::onTransformEvent(Util::Game::TransformEvent *event) {
    auto transformTo = event->getTransformTo();
    if (transformTo.getX() > 1 || transformTo.getX() < (-1 - getSize())
        || transformTo.getY() > (1 - getSize()) || transformTo.getY() < -1) {
        event->setCanceled(true);
    }
}

void SnakeEntity::move() {
    switch (direction) {
        case right:
            transform(Vector2(speed, 0));
            return;
        case left:
            transform(Vector2(-speed, 0));
            return;
        case up:
            transform(Vector2(0, speed));
            return;
        case down:
            transform(Vector2(0, -speed));
            return;
    }
}


