//
// Created by Malte Sehmer on 07.12.22.
//

#include "PlatformerGame.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "lib/util/game/GameManager.h"
#include "entity/PlatformerNinjaEntity.h"
#include "scene/PlatformerScene2.h"
#include "lib/util/stream/FileReader.h"
#include "application/platformer/block/PlatformerBrickBlockEntity.h"
#include "application/platformer/block/PlatformerItemBlockEntity.h"
#include "lib/util/file/File.h"

void PlatformerGame::onUpdate(double delta) {

}

void PlatformerGame::spawnNinja(const Vector2 &position, double groundY) {
    auto scene = getScene();
    if (scene != nullptr) {
        auto newNinja = new PlatformerNinjaEntity(position);
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
}

void PlatformerGame::createSceneFromSceneFile(Util::Game::Scene *scene, const char *fileName) {
    auto sceneFile = Util::File::File(fileName);
    auto fileReader = Util::Stream::FileReader(sceneFile);

    auto x = -1;
    auto y = (Util::Game::GameManager::getResolution().getY() / 2);

    auto dirtPositions = Util::Data::ArrayList<Util::Data::Pair<int, double>>();

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
            case '3':
                dirtPositions.add({x, y});
                break;
        }
        c = fileReader.read();
        x += 1;
    }
    spawnLargeColliderFromArray(*scene, dirtPositions);
}

void PlatformerGame::spawnLargeColliderFromArray(Util::Game::Scene &scene,
                                                 Util::Data::ArrayList<Util::Data::Pair<int, double>> &positions) {
    if (positions.isEmpty()) return;

    auto lastPoint = positions.get(0);
    auto rectangleStartPoint = lastPoint;
    for (auto point: positions) {
        if (point.first - 1 == lastPoint.first) {

        } else {
            auto rectangleStartVec = Vector2(
                    rectangleStartPoint.first * blockSize - (Util::Game::GameManager::getResolution().getX() / 2),
                    rectangleStartPoint.second);
            scene.addEntity(
                    new PlatformerBrickBlockEntity(rectangleStartVec, lastPoint.first - rectangleStartPoint.first));

            rectangleStartPoint = point;
        }
        lastPoint = point;
    }
}


