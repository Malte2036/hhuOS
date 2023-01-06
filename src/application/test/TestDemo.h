//
// Created by malte on 04.12.22.
//

#ifndef HHUOS_TESTDEMO_H
#define HHUOS_TESTDEMO_H


#include "lib/util/game/Game.h"

class TestDemo : public Util::Game::Game, public Util::Game::KeyListener{

public:
    TestDemo();

    void update(double delta) override;

    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;

    void keyPressed(char c) override;
};


#endif //HHUOS_TESTDEMO_H
