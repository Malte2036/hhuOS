//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_MARIOGAME_H
#define HHUOS_MARIOGAME_H

#include "lib/util/game/Game.h"
#include "application/mario/entity/MarioEntity.h"
#include "application/mario/block/MarioItemBlockEntity.h"

class MarioGame : public Util::Game::Game, public Util::Game::KeyListener {

public:
    MarioGame();

    void update(double delta);

    void keyPressed(char c) override;

    void spawnGoomba(Vector2 position);

    const double getGroundY();

private:
    MarioEntity *player = nullptr;
    const double groundY = -0.75;
};

#endif //HHUOS_MARIOGAME_H
