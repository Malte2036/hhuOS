//
// Created by Malte Sehmer on 07.12.22.
//

#ifndef HHUOS_PLATFORMERGAME_H
#define HHUOS_PLATFORMERGAME_H

#include "lib/util/game/Game.h"

class PlatformerGame : public Util::Game::Game {

public:
    PlatformerGame() = default;

    void spawnNinja(const Vector2 &position, double groundY);

    void nextLevel();

    double getBlockSize();

    void createSceneFromSceneFile(Util::Game::Scene* scene, const char* fileName);

private:
    void init() override;

    void onUpdate(double delta) override;

    double blockSize = 0.08;

    int currentLevel = 1;
};

#endif //HHUOS_PLATFORMERGAME_H
