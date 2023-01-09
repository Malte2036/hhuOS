//
// Created by malte on 09.01.23.
//

#include "MouseGameScene.h"
#include "lib/util/game/GameManager.h"
#include "MouseGame.h"

void MouseGameScene::init() {
    addObject(cursor);
    setKeyListener(*this);
    setMouseListener(*cursor);
}

void MouseGameScene::update(double dt) {

}

void MouseGameScene::drawInitialBackground(Util::Game::Graphics2D &graphics) {

}

void MouseGameScene::keyPressed(char c) {
    Util::Game::GameManager::getGame<MouseGame>()->stop();
}
