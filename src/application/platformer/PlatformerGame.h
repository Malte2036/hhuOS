//
// Created by malte on 07.12.22.
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

    void createSceneFromSceneFile(Util::Game::Scene *scene, const char *fileName);

private:
    void init() override;

    void onUpdate(double delta) override;

    void spawnLargeColliderFromArray(Util::Game::Scene &scene,
                                     Util::Data::ArrayList<Util::Data::Pair<int, double>> &positions);

    double blockSize = 0.08;

    int currentLevel = 1;
};

#endif //HHUOS_PLATFORMERGAME_H
