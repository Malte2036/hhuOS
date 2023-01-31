//
// Created by Malte Sehmer on 09.01.23.
//

#include "MouseGameScene.h"
#include "lib/util/game/GameManager.h"
#include "MouseGame.h"

void MouseGameScene::init() {
    addObject(cursor);
    setKeyListener(*this);
    setMouseListener(*cursor);
}

void MouseGameScene::onUpdate(double dt) {

}

void MouseGameScene::drawInitialBackground(Util::Game::Graphics2D &graphics) {

}
void MouseGameScene::keyPressed(Util::Io::Key key) {
    Util::Game::GameManager::getGame<MouseGame>()->stop();
}

void MouseGameScene::keyReleased(Util::Io::Key key) {

}