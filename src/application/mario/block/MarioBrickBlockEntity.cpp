//
// Created by malte on 07.12.22.
//

#include "MarioBrickBlockEntity.h"
#include "lib/util/game/GameManager.h"

MarioBrickBlockEntity::MarioBrickBlockEntity(const Vector2 &position)
        : Util::Game::Entity("BrickBlock", position),
          sprite{new Util::Game::Sprite("/initrd/game/platformer/block/block_brick.bmp")} {
    collider = new Util::Game::RectangleCollider(position, size, size, Util::Game::STATIC_COLLIDER);
}

void MarioBrickBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
    //graphics.drawSquare(position, size);
}

void MarioBrickBlockEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void MarioBrickBlockEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWith()->getTag() == "Player") {
        //Util::Game::GameManager::getGame<MarioGame>()->removeEntity(this);
    }
}

void MarioBrickBlockEntity::onUpdate(double dt) {

}
