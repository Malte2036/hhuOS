//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_PLATFORMERGAME_H
#define HHUOS_PLATFORMERGAME_H

#include "lib/util/game/Game.h"

class PlatformerGame : public Util::Game::Game {

public:
    PlatformerGame() = default;

    void update(double delta) override {

    }

    void keyPressed(char c) {

    }

    void spawnNinja(Vector2 position);

private:
    const double groundY = -0.75;

};

#endif //HHUOS_PLATFORMERGAME_H
