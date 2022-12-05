//
// Created by malte on 04.12.22.
//

#include "TestDemo.h"

#include "lib/util/system/System.h"
#include "lib/util/data/Array.h"
#include "DemoEntity.h"


auto sprites = Util::Data::Array<DemoEntity *>(2);

TestDemo::TestDemo() {
    Util::System::out << "Starting testDemo\n";

    DemoEntity *s = new DemoEntity(0, 0, Util::Graphic::Colors::HHU_BLUE, right);
    sprites[0] = s;

    addObject(s);

    setKeyListener(*this);
}


void TestDemo::update(double delta) {
    auto player = sprites[0];
    /*if(player->getX() >= 1){
        player->setDirection(left);
        player->setColor(Util::Graphic::Colors::CYAN);
    }else if(player->getX() <= -1){
        player->setDirection(right);
        player->setColor(Util::Graphic::Colors::GREEN);
    }*/

    double speed = 0.03;
    double xForce = 0;
    double yForce = 0;

    switch (player->getDirection()) {
        case up:
            yForce = speed;
            break;
        case down:
            yForce = -speed;
            break;
        case left:
            xForce = -speed;
            break;
        case right:
            xForce = speed;
            break;
    }

    sprites[0]->transform(xForce, yForce);

    //Util::System::out << "update\n";

    auto color = Util::Graphic::Colors::BLACK;
}

void TestDemo::keyPressed(char c) {
    auto player = sprites[0];
    switch (c) {
        case 'w':
            player->setDirection(up);
            break;
        case 'a':
            player->setDirection(left);
            break;
        case 's':
            player->setDirection(down);
            break;
        case 'd':
            player->setDirection(right);
            break;
        case 'q':
            stop();
            break;
        default:
            player->setColor(Util::Graphic::Colors::RED);
    }
}