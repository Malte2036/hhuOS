//
// Created by malte on 04.12.22.
//

#ifndef HHUOS_TESTDEMO_H
#define HHUOS_TESTDEMO_H


#include "lib/util/game/Game.h"

class TestDemo : public Util::Game::Game{

public:
    TestDemo();

    void update(double delta);
};


#endif //HHUOS_TESTDEMO_H
