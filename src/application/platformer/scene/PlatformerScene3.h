//
// Created by Malte Sehmer on 01.02.23.
//

#ifndef HHUOS_PLATFORMERSCENE3_H
#define HHUOS_PLATFORMERSCENE3_H


#include "application/platformer/entity/PlatformerPlayerEntity.h"
#include "application/platformer/text/PlatformerScoreText.h"
#include "lib/util/io/Key.h"
#include "lib/util/game/scene/Scene.h"

class PlatformerScene3 : public Util::Game::Scene, public Util::Game::KeyListener {
public:
    PlatformerScene3() = default;

private:
    void init() override;

    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;

    void onUpdate(double dt) override;

    void keyPressed(Util::Io::Key key) override;

    void keyReleased(Util::Io::Key key) override;

private:

    PlatformerPlayerEntity *player = nullptr;
    const double groundY = -2;

    PlatformerScoreText *scoreText = nullptr;
};


#endif //HHUOS_PLATFORMERSCENE3_H
