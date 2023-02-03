//
// Created by Malte Sehmer on 07.12.22.
//

#include "PlatformerItemBlockEntity.h"
#include "lib/util/game/GameManager.h"
#include "../PlatformerGame.h"
#include "PlatformerSolidBlockEntity.h"
#include "../entity/PlatformerMushroomEntity.h"
#include "lib/util/game/entity/component/GravityComponent.h"

PlatformerItemBlockEntity::PlatformerItemBlockEntity(const Vector2 &position)
        : PlatformerBlockEntity("ItemBlock", position, "/initrd/game/platformer/block/block_item.bmp") {
}

void PlatformerItemBlockEntity::onCollisionEvent(Util::Game::CollisionEvent &event) {
    if (event.getCollidedWith().getTag() == "Player") {
        if (event.getRectangleCollidedSide() == Util::Game::BOTTOM_SIDE) {
            auto game = Util::Game::GameManager::getGame<PlatformerGame>();
            auto scene = game->getScene();
            scene->addEntity(new PlatformerSolidBlockEntity(position));

            auto mushroom = new PlatformerMushroomEntity(position + Vector2(0, game->getBlockSize()));
            mushroom->addComponent(new Util::Game::GravityComponent(-0.5));
            scene->addEntity(mushroom);

            scene->removeEntity(this);
        }
    }
}
