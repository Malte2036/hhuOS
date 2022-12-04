//
// Created by malte on 04.12.22.
//

#include "TestDemo.h"

#include "lib/util/system/System.h"
#include "lib/util/data/Array.h"
#include "DemoSprite.h"



auto sprites = Util::Data::Array<DemoSprite*>(2);
TestDemo::TestDemo() {
    Util::System::out << "Starting testDemo\n";

    DemoSprite *s = new DemoSprite(0, 0, Util::Graphic::Colors::BLUE, right);
    sprites[0] = s;

    addObject(s);
}


void TestDemo::update(double delta) {
    auto player = sprites[0];
    if(player->getX() >= 1){
        player->setDirection(left);
        player->setColor(Util::Graphic::Colors::CYAN);
    }else if(player->getX() <= -1){
        player->setDirection(right);
        player->setColor(Util::Graphic::Colors::GREEN);
    }

    double xForce = 0.02;
    if(player->getDirection() == left){
        xForce *= -1;
    }
    sprites[0]->transform(xForce, 0);

    //Util::System::out << "update\n";

    auto color = Util::Graphic::Colors::BLACK;
}