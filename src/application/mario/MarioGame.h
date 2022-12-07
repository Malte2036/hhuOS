//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_MARIOGAME_H
#define HHUOS_MARIOGAME_H

#include "lib/util/game/Game.h"
#include "MarioEntity.h"
#include "MarioItemBlockEntity.h"

class MarioGame : public Util::Game::Game, public Util::Game::KeyListener {

public:
    MarioGame();

    void update(double delta);

    void keyPressed(char c) override;

private:
    MarioEntity *player = nullptr;

    Util::Data::ArrayList<MarioItemBlockEntity*> itemBlocks = {};
};

#endif //HHUOS_MARIOGAME_H
