//
// Created by malte on 04.12.22.
//

#include "DemoEntity.h"

DemoEntity::DemoEntity(const Vector2& position, double size, Util::Graphic::Color color, DirectionType direction) : Entity(
        position), color{color}, direction{direction}, size{size} {}

void DemoEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.setColor(color);
    graphics.drawRectangle(getPosition(), size);
}

DirectionType DemoEntity::getDirection() {
    return direction;
}

void DemoEntity::setDirection(DirectionType directionType) {
    direction = directionType;
}

void DemoEntity::setColor(Util::Graphic::Color value) {
    color = value;
}

void DemoEntity::onTransformEvent(Util::Game::TransformEvent *event) {
    auto transformTo = event->getTransformTo();

    if (transformTo.getX() > 1 || transformTo.getX() < -1 ||
        transformTo.getY() > (1 - size) || transformTo.getY() < -1) {
        event->setCanceled(true);
    }
}

Util::Game::RectangleCollider DemoEntity::getCollider() const {
    return Util::Game::RectangleCollider(size, size);
}
