//
// Created by malte on 04.12.22.
//

#include "TestDemo.h"

#include "lib/util/system/System.h"


TestDemo::TestDemo() {
    Util::System::out << "Starting testDemo\n";
}


void TestDemo::update(double delta) {

    Util::System::out << "update\n";
}
