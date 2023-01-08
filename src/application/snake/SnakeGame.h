//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_SNAKEGAME_H
#define HHUOS_SNAKEGAME_H

#include "lib/util/game/Game.h"


struct SnakeGameData {
    int score;
};

class SnakeGame : public Util::Game::Game {

public:
    SnakeGame();

    void update(double dt) override;

    SnakeGameData getSnakeGameData();

    void setSnakeGameData(SnakeGameData value);

private:
    SnakeGameData gameData;
};


#endif //HHUOS_SNAKEGAME_H
