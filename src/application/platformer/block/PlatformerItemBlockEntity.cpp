//
// Created by malte on 07.12.22.
//

#include "PlatformerItemBlockEntity.h"
#include "lib/util/game/GameManager.h"
#include "../PlatformerGame.h"
#include "PlatformerSolidBlockEntity.h"
#include "../entity/PlatformerMushroomEntity.h"
#include "lib/util/game/entity/component/GravityComponent.h"

PlatformerItemBlockEntity::PlatformerItemBlockEntity(const Vector2 &position)
        : Util::Game::Entity("ItemBlock", position),
          sprite{new Util::Game::Sprite("/initrd/game/platformer/block/block_item.bmp")} {

    collider = new Util::Game::RectangleCollider(position, size, size, Util::Game::STATIC_COLLIDER);
}

void PlatformerItemBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
    //graphics.drawSquare(position, size);
}

void PlatformerItemBlockEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void PlatformerItemBlockEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWith()->getTag() == "Player") {
        if (event->getRectangleCollidedSide() == Util::Game::BOTTOM_SIDE) {
            auto game = Util::Game::GameManager::getGame<PlatformerGame>();
            game->addEntity(new PlatformerSolidBlockEntity(position));

            auto mushroom = new PlatformerMushroomEntity(position + Vector2(0, size));
            mushroom->addComponent(new Util::Game::GravityComponent(-0.5));
            game->addEntity(mushroom);

            game->removeEntity(this);
        }
    }
}

void PlatformerItemBlockEntity::onUpdate(double dt) {

}
