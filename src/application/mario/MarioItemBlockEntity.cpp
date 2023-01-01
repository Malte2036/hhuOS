//
// Created by malte on 07.12.22.
//

#include "MarioItemBlockEntity.h"
#include "lib/util/game/GameManager.h"
#include "MarioGame.h"

MarioItemBlockEntity::MarioItemBlockEntity(const Util::Memory::String &tag, const Vector2 &position)
        : Util::Game::Entity(tag, position),sprite{new Util::Game::Sprite("/initrd/mario_block.bmp")} {

}

Util::Game::RectangleCollider MarioItemBlockEntity::getCollider() const {
    return Util::Game::RectangleCollider(position, size, size);
}

void MarioItemBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
    graphics.drawSquare(position, size);
}

void MarioItemBlockEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void MarioItemBlockEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if(event->getCollidedWith()->getTag() == "Player"){
        //Util::Game::GameManager::getGame<MarioGame>()->removeEntity(this);
    }
}

void MarioItemBlockEntity::onUpdate(double dt) {

}
