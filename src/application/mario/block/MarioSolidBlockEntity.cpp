//
// Created by malte on 07.12.22.
//

#include "MarioSolidBlockEntity.h"
#include "lib/util/game/GameManager.h"

MarioSolidBlockEntity::MarioSolidBlockEntity(const Vector2 &position)
        : Util::Game::Entity("SolidBlock", position), sprite{new Util::Game::Sprite("/initrd/mario_solidblock.bmp")} {

}

Util::Game::RectangleCollider MarioSolidBlockEntity::getCollider() const {
    return Util::Game::RectangleCollider(position, size, size, Util::Game::STATIC_COLLIDER);
}

void MarioSolidBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
    graphics.drawSquare(position, size);
}

void MarioSolidBlockEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void MarioSolidBlockEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWith()->getTag() == "Player") {
        //Util::Game::GameManager::getGame<MarioGame>()->removeEntity(this);
    }
}

void MarioSolidBlockEntity::onUpdate(double dt) {

}
