//
// Created by malte on 04.12.22.
//

#include "DemoEntity.h"

const double speed = 0.75;

DemoEntity::DemoEntity(const Vector2 &position, const double size) : GravityEntity("DemoEntity", position, 1), size{size},
                                                  sprite{Util::Game::Sprite("/initrd/mario.bmp")} {

}

void DemoEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(getPosition().getX(), getPosition().getY(), *sprite.getImage());
}

void DemoEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {
    auto transformTo = event->getTranslateTo();
    if (transformTo.getX() > 1 || transformTo.getX() < -1) {
        event->setCanceled(true);
    }
    if (transformTo.getY() > (1 - size) || transformTo.getY() < -1) {
        event->setCanceled(true);
    }
}

Util::Game::RectangleCollider DemoEntity::getCollider() const {
    return Util::Game::RectangleCollider(getPosition(), size, size);
}

void DemoEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {

}

void DemoEntity::moveRight() {
    translateX(speed);
}

void DemoEntity::moveLeft() {
    translateX(-speed);
}

void DemoEntity::jump() {
    if (getPosition().getY() <= (-1 + 0.025)) {
        translateY(speed * 2);
    }
}
