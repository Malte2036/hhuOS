//
// Created by malte on 04.12.22.
//

#include "DemoEntity.h"

const double speed = 0.75;

DemoEntity::DemoEntity(const Vector2 &position, double size, Util::Graphic::Color color) : GravityEntity(
        position), color{color}, size{size} {}

void DemoEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.setColor(color);
    graphics.drawSquare(getPosition(), size);
}

void DemoEntity::onTransformEvent(Util::Game::TransformEvent *event) {
    auto transformTo = event->getTransformTo();
    if(transformTo.getX() > 1 || transformTo.getX() < -1){
        event->setCanceled(true);
    }
    if(transformTo.getY() > (1 - size) || transformTo.getY() < -1){
        event->setCanceled(true);
    }
}

Util::Game::RectangleCollider DemoEntity::getCollider() const {
    return Util::Game::RectangleCollider(getPosition(), size, size);
}

void DemoEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {

}

void DemoEntity::moveRight() {
    transformX(speed);
}

void DemoEntity::moveLeft() {
    transformX(-speed);
}

void DemoEntity::moveUp() {
    transformY(speed);
}


void DemoEntity::moveDown() {
    transformY(-speed);
}
