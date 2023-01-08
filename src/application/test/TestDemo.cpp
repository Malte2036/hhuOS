//
// Created by malte on 04.12.22.
//

#include "TestDemo.h"

#include "lib/util/system/System.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "DemoEntity.h"


DemoEntity *player = nullptr;

TestDemo::TestDemo() {
    Util::System::out << "Starting testDemo\n";

    player = new DemoEntity(Vector2(0, 0), 0.1);
    player->addComponent(new Util::Game::GravityComponent(-1));
    addEntity(player);

    setKeyListener(*this);
}


void TestDemo::update(double delta) {

}

void TestDemo::keyPressed(char c) {
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
            stop();
            return;
    }
}
