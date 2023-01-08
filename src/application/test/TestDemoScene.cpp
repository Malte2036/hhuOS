//
// Created by malte on 08.01.23.
//

#include "TestDemoScene.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "lib/util/game/GameManager.h"
#include "TestDemo.h"

void TestDemoScene::init() {
    player = new DemoEntity(Vector2(0, 0), 0.1);
    player->addComponent(new Util::Game::GravityComponent(-1));
    addEntity(player);

    setKeyListener(*this);
}

void TestDemoScene::drawInitialBackground(Util::Game::Graphics2D &graphics) {

}

void TestDemoScene::update(double dt) {

}

void TestDemoScene::keyPressed(char c) {
    switch (c) {
        case 'a':
            player->moveLeft();
            return;
        case 'd':
            player->moveRight();
            return;
        case 'w':
            player->jump();
            return;
        case 'q':
            Util::Game::GameManager::getGame<TestDemo>()->stop();
            return;
    }
}
