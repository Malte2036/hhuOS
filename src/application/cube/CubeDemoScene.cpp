//
// Created by malte on 09.01.23.
//

#include "CubeDemoScene.h"
#include "lib/util/game/GameManager.h"
#include "CubeDemo.h"

CubeDemoScene::CubeDemoScene(int32_t speed) : speed{speed} {

}

void CubeDemoScene::init() {
    for (auto *cube: cubes) {
        addObject(cube);
    }

    setKeyListener(*this);
}

void CubeDemoScene::onUpdate(double dt) {
    for (auto &cube: cubes) {
        cube->rotate(ANGLE_X * speed * dt, ANGLE_Y * speed * dt, ANGLE_Z * speed * dt);
    }
}

void CubeDemoScene::drawInitialBackground(Util::Game::Graphics2D &graphics) {

}

void CubeDemoScene::keyPressed(char c) {
    switch (c) {
        case '+': {
            speed++;
            break;
        }
        case '-': {
            speed--;
            break;
        }
        default:
            Util::Game::GameManager::getGame<CubeDemo>()->stop();
    }
}
