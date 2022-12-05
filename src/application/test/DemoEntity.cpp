//
// Created by malte on 04.12.22.
//

#include "DemoEntity.h"

DemoEntity::DemoEntity(Vector2 position, double size, Util::Graphic::Color color, DirectionType direction) : Entity(
        position, size, color), direction{direction} {}

void DemoEntity::draw(Util::Game::Graphics2D &graphics) const {
    Entity::draw(graphics);
}

DirectionType DemoEntity::getDirection() {
    return direction;
}

void DemoEntity::setDirection(DirectionType directionType) {
    direction = directionType;
}

void DemoEntity::onTransformEvent(Vector2 vector2) {
    if (vector2.getX() > 1) {
        vector2 = Vector2(1, vector2.getY());
    } else if (vector2.getX() < -1) {
        vector2 = Vector2(-1, vector2.getY());
    }

    if (vector2.getY() > (1 - getSize())) {
        vector2 = Vector2(vector2.getX(), 1 - getSize());
    } else if (vector2.getY() < -1) {
        vector2 = Vector2(vector2.getX(), -1);
    }
    setPosition(vector2);
}
