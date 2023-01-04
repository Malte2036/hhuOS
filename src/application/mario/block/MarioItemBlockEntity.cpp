//
// Created by malte on 07.12.22.
//

#include "MarioItemBlockEntity.h"
#include "lib/util/game/GameManager.h"
#include "application/mario/MarioGame.h"
#include "MarioSolidBlockEntity.h"
#include "application/mario/entity/MarioMushroomEntity.h"
#include "lib/util/game/entity/component/GravityComponent.h"

MarioItemBlockEntity::MarioItemBlockEntity(const Vector2 &position)
        : Util::Game::Entity("ItemBlock", position), sprite{new Util::Game::Sprite("/initrd/mario_itemblock.bmp")} {

}

Util::Game::RectangleCollider MarioItemBlockEntity::getCollider() const {
    return Util::Game::RectangleCollider(position, size, size, Util::Game::STATIC_COLLIDER);
}

void MarioItemBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
    graphics.drawSquare(position, size);
}

void MarioItemBlockEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void MarioItemBlockEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWith()->getTag() == "Player") {
        if (event->getRectangleCollidedSide() == Util::Game::BOTTOM_SIDE) {
            auto game = Util::Game::GameManager::getGame<MarioGame>();
            game->addEntity(new MarioSolidBlockEntity(position));

            auto mushroom = new MarioMushroomEntity(position + Vector2(0, size));
            mushroom->addComponent(new Util::Game::GravityComponent(-0.5));
            game->addEntity(mushroom);

            game->removeEntity(this);
        }
    }
}

void MarioItemBlockEntity::onUpdate(double dt) {

}
