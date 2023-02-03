//
// Created by Malte Sehmer on 10.01.23.
//

#include "PlatformerChestEntity.h"

PlatformerChestEntity::PlatformerChestEntity(const Vector2 &position) : Util::Game::Entity("Chest", position) {
    sprite = new Util::Game::Sprite("initrd/game/platformer/special/chest.bmp", width, height);
    collider = new Util::Game::RectangleCollider(position, height, width, Util::Game::STATIC_COLLIDER);
}

void PlatformerChestEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
}

void PlatformerChestEntity::onUpdate(double dt) {

}

void PlatformerChestEntity::onTranslateEvent(Util::Game::TranslateEvent &event) {

}

void PlatformerChestEntity::onCollisionEvent(Util::Game::CollisionEvent &event) {

}

