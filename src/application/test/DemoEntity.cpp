//
// Created by malte on 04.12.22.
//

#include "DemoEntity.h"

DemoEntity::DemoEntity(Vector2 position, Util::Graphic::Color color, DirectionType direction) : Entity(position, color), direction{direction} {}

void DemoEntity::draw(Util::Game::Graphics2D &graphics) const {
    Entity::draw(graphics);
}

DirectionType DemoEntity::getDirection() {
    return direction;
}

void DemoEntity::setDirection(DirectionType directionType) {
    direction = directionType;
}
