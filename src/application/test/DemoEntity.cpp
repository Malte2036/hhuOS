//
// Created by malte on 04.12.22.
//

#include "DemoEntity.h"
#include "lib/util/system/System.h"

DemoEntity::DemoEntity(double initialX, double initialY, Util::Graphic::Color initialColor, DirectionType initialDirection) : Entity(initialX, initialY, initialColor) {
    direction = initialDirection;
}

void DemoEntity::draw(Util::Game::Graphics2D &graphics) const {
    Entity::draw(graphics);
}

DirectionType DemoEntity::getDirection() {
    return direction;
}

void DemoEntity::setDirection(DirectionType directionType) {
    direction = directionType;
}
