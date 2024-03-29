//
// Created by Malte Sehmer on 04.12.22.
//

#include "DemoEntity.h"

const double speed = 0.75;

DemoEntity::DemoEntity(const Vector2 &position, const double size) : Entity("DemoEntity", position), size{size} {
    sprite = new Util::Game::Sprite("/initrd/game/platformer/player/run/player_run_1.bmp", size, size);
    collider = new Util::Game::RectangleCollider(getPosition(), size, size, Util::Game::STATIC_COLLIDER);
}

void DemoEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(getPosition(), *sprite->getImage());
}

void DemoEntity::onTranslateEvent(Util::Game::TranslateEvent &event) {
    auto transformTo = event.getTranslateTo();
    if (transformTo.getX() > 1 || transformTo.getX() < -1) {
        event.setCanceled(true);
    }
    if (transformTo.getY() > (1 - size) || transformTo.getY() < -1) {
        event.setCanceled(true);
    }
}

void DemoEntity::onCollisionEvent(Util::Game::CollisionEvent &event) {

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

void DemoEntity::onUpdate(double dt) {

}

void DemoEntity::init() {

}
