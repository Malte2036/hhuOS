//
// Created by malte on 07.12.22.
//

#include "PlatformerSolidBlockEntity.h"
#include "lib/util/game/GameManager.h"

PlatformerSolidBlockEntity::PlatformerSolidBlockEntity(const Vector2 &position)
        : Util::Game::Entity("SolidBlock", position) {

    sprite = new Util::Game::Sprite("/initrd/mario_solidblock.bmp", size, size);
    collider = new Util::Game::RectangleCollider(position, size, size, Util::Game::STATIC_COLLIDER);
}

void PlatformerSolidBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
    graphics.drawSquare(position, size);
}

void PlatformerSolidBlockEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void PlatformerSolidBlockEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWith().getTag() == "Player") {
        //Util::Game::GameManager::getGame<PlatformerGame>()->removeEntity(this);
    }
}

void PlatformerSolidBlockEntity::onUpdate(double dt) {

}
