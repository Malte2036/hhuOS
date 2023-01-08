//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_PLATFORMERGAME_H
#define HHUOS_PLATFORMERGAME_H

#include "lib/util/game/Game.h"

class PlatformerGame : public Util::Game::Game {

public:
    PlatformerGame() = default;

    void spawnNinja(const Vector2& position);

    void nextLevel();

private:
    void update(double delta) override;

    const double groundY = -0.75;
    int currentLevel = 1;
};

#endif //HHUOS_PLATFORMERGAME_H
