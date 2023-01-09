//
// Created by malte on 07.12.22.
//

#include "PlatformerGame.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "lib/util/game/GameManager.h"
#include "entity/PlatformerNinjaEntity.h"
#include "scene/PlatformerScene2.h"

void PlatformerGame::update(double delta) {

}

void PlatformerGame::spawnNinja(const Vector2& position, double groundY) {
    auto scene = getScene();
    if (scene != nullptr) {
        auto newNinja = new PlatformerNinjaEntity(position, groundY);
        newNinja->addComponent(new Util::Game::GravityComponent(groundY));
        scene->addEntity(newNinja);
    }
}

void PlatformerGame::nextLevel() {
    currentLevel++;

    Util::Game::Scene *newScene = nullptr;
    if (currentLevel == 2) {
        newScene = new PlatformerScene2();
    }

    if (newScene != nullptr) {
        pushScene(newScene);
        return;
    }
    stop();
}
