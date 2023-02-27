//
// Created by Malte Sehmer on 03.01.23.
//

#include "PlatformerItemEntity.h"
#include "lib/util/game/GameManager.h"
#include "../PlatformerGame.h"
#include "lib/util/log/Logger.h"

PlatformerItemEntity::PlatformerItemEntity(const Vector2 &position) : Util::Game::Entity("Item", position) {
    sprite = new Util::Game::Sprite("/initrd/game/platformer/item/item.bmp", width, height);
    collider = new Util::Game::RectangleCollider(position, height, width, Util::Game::DYNAMIC_COLLIDER);
}

PlatformerItemEntity::~PlatformerItemEntity() {
    delete sprite;
}

void PlatformerItemEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage(), directionLeft);
    /*graphics.drawRectangle(position,
                           getCollider()->getHeight(),
                           getCollider()->getWidth());*/
}

void PlatformerItemEntity::onUpdate(double dt) {
    translateX(speed * (directionLeft ? -1 : 1));
}

void PlatformerItemEntity::onCollisionEvent(Util::Game::CollisionEvent &event) {
    auto collidedWithSide = event.getRectangleCollidedSide();
    if (collidedWithSide == Util::Game::LEFT_SIDE) {
        directionLeft = false;
    } else if (collidedWithSide == Util::Game::RIGHT_SIDE) {
        directionLeft = true;
    }
}

void PlatformerItemEntity::onTranslateEvent(Util::Game::TranslateEvent &event) {

}

void PlatformerItemEntity::init() {

}
