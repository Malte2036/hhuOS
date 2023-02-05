//
// Created by Malte Sehmer on 07.12.22.
//

#ifndef HHUOS_PLATFORMERGAME_H
#define HHUOS_PLATFORMERGAME_H

#include "lib/util/game/Game.h"
#include "application/platformer/text/PlatformerProjectileText.h"

class PlatformerGame : public Util::Game::Game {

public:
    PlatformerGame() = default;

    void spawnNinja(const Vector2 &position, double groundY = -2);

    void nextLevel();

    double getBlockSize();

    void createSceneFromSceneFile(Util::Game::Scene *scene, const Util::Memory::String &fileName);

    void showProjectileCount(int count);

protected:
    friend class PlatformerScene;
    PlatformerProjectileText *projectileText = nullptr;

private:
    void init() override;

    void onUpdate(double delta) override;

    enum LargeColliderType {
        DIRT, GRASS, LAVA
    };

    void spawnLargeColliderFromArray(Util::Game::Scene &scene,
                                     Util::Data::ArrayList<Util::Data::Pair<int, double>> &positions,
                                     LargeColliderType type) const;

    double blockSize = 0.08;

    int currentLevel = 1;

};

#endif //HHUOS_PLATFORMERGAME_H
