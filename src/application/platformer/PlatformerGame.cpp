//
// Created by malte on 07.12.22.
//

#include "PlatformerGame.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "lib/util/game/GameManager.h"
#include "entity/PlatformerNinjaEntity.h"
#include "scene/PlatformerScene2.h"
#include "lib/util/stream/FileReader.h"
#include "application/platformer/block/PlatformerBrickBlockEntity.h"
#include "application/platformer/block/PlatformerItemBlockEntity.h"
#include "lib/util/game/entity/collider/PolygonCollider.h"
#include "lib/util/game/entity/collider/Collider.h"

void PlatformerGame::onUpdate(double delta) {

}

void PlatformerGame::spawnNinja(const Vector2 &position, double groundY) {
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

double PlatformerGame::getBlockSize() {
    return blockSize;
}

void PlatformerGame::init() {
    //Util::Game::GameManager::playSound("/initrd/beep/mario.beep");

    /*auto vertices = Util::Data::Array<Vector2>({Vector2(0, 0), Vector2(0, 1), Vector2(12, 1), Vector2(1, 0)});
    auto coll = Util::Game::PolygonCollider(vertices);

    auto offset = Vector2(2, 5);
    auto verticesOther = Util::Data::Array<Vector2>(
            {Vector2(0, 0) + offset, Vector2(0, 1) + offset, Vector2(1, 1) + offset, Vector2(1, 0) + offset});
    auto collOther = Util::Game::PolygonCollider(verticesOther);
    auto res = coll.isColliding(collOther);*/
}

void PlatformerGame::createSceneFromSceneFile(Util::Game::Scene *scene, const char *fileName) {
    auto sceneFile = Util::File::File(fileName);
    auto fileReader = Util::Stream::FileReader(sceneFile);

    auto x = -1;
    auto y = (Util::Game::GameManager::getResolution().getY() / 2);

    auto c = fileReader.read();
    while (c != -1) {
        auto pos = Vector2(x * blockSize - (Util::Game::GameManager::getResolution().getX() / 2), y);
        switch (c) {
            case '\n':
                x = -1;
                y -= blockSize;
                break;
            case '1':
                scene->addEntity(new PlatformerBrickBlockEntity(pos));
                break;
            case '2':
                scene->addEntity(new PlatformerItemBlockEntity(pos));
                break;
        }
        c = fileReader.read();
        x += 1;
    }
}
