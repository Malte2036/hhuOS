//
// Created by malte on 07.12.22.
//

#include "PlatformerGame.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "lib/util/game/GameManager.h"
#include "entity/PlatformerNinjaEntity.h"
#include "block/PlatformerBrickBlockEntity.h"
#include "block/PlatformerSolidBlockEntity.h"

void PlatformerGame::spawnNinja(Vector2 position) {
    auto scene = getScene();
    if (scene != nullptr) {
        auto newNinja = new PlatformerNinjaEntity(position + Vector2(1.5, 0));
        newNinja->addComponent(new Util::Game::GravityComponent(groundY));
        scene->addEntity(newNinja);
    }
}

void PlatformerGame::update(double delta) {

}
