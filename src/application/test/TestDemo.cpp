//
// Created by malte on 04.12.22.
//

#include "TestDemo.h"

#include "lib/util/system/System.h"
#include "DemoSprite.h"


TestDemo::TestDemo() {
    Util::System::out << "Starting testDemo\n";

    DemoSprite *s = new DemoSprite(0, 0, Util::Graphic::Colors::BLUE);

    addObject(s);
}


void TestDemo::update(double delta) {

    //Util::System::out << "update\n";

    auto color = Util::Graphic::Colors::BLACK;
}