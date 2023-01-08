//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_SNAKEGAME_H
#define HHUOS_SNAKEGAME_H

#include "lib/util/game/Game.h"


struct SnakeGameData {
    int score;
};

class SnakeGame : public Util::Game::Game, public Util::Game::KeyListener {


public:

    SnakeGame();

    void update(double dt) override;

        void keyPressed(char c) override;

private:
    SnakeGameData gameData;
};


#endif //HHUOS_SNAKEGAME_H
