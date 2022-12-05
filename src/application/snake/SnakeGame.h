//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_SNAKEGAME_H
#define HHUOS_SNAKEGAME_H

#include "lib/util/game/Game.h"

class SnakeGame : public Util::Game::Game, public Util::Game::KeyListener {
public:
    SnakeGame();

    void update(double delta);

    void keyPressed(char c) override;
};


#endif //HHUOS_SNAKEGAME_H
