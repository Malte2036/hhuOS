//
// Created by malte on 04.12.22.
//

#ifndef HHUOS_TESTDEMO_H
#define HHUOS_TESTDEMO_H


#include "lib/util/game/Game.h"

class TestDemo : public Util::Game::Game {

public:
    TestDemo();

private:
    void onUpdate(double delta) override;
};


#endif //HHUOS_TESTDEMO_H
