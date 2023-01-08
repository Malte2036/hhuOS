//
// Created by malte on 07.12.22.
//

#include "PlatformerBrickBlockEntity.h"
#include "lib/util/game/GameManager.h"

PlatformerBrickBlockEntity::PlatformerBrickBlockEntity(const Vector2 &position)
        : Util::Game::Entity("BrickBlock", position),
          sprite{new Util::Game::Sprite("/initrd/game/platformer/block/block_brick.bmp")} {
    collider = new Util::Game::RectangleCollider(position, size, size, Util::Game::STATIC_COLLIDER);
}

void PlatformerBrickBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
    //graphics.drawSquare(position, size);
}

void PlatformerBrickBlockEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void PlatformerBrickBlockEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWith()->getTag() == "Player") {
        //Util::Game::GameManager::getGame<PlatformerGame>()->removeEntity(this);
    }
}

void PlatformerBrickBlockEntity::onUpdate(double dt) {

}
