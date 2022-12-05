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

void DemoEntity::onTransformEvent(Util::Game::TransformEvent *event) {
    auto transformTo = event->getTransformTo();

    if (transformTo.getX() > 1 || transformTo.getX() < -1 ||
        transformTo.getY() > (1 - getSize()) || transformTo.getY() < -1) {
        event->setCanceled(true);
    }
}
