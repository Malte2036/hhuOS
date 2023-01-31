//
// Created by Malte Sehmer on 08.01.23.
//

#ifndef HHUOS_PLATFORMERSCENE1_H
#define HHUOS_PLATFORMERSCENE1_H

#include "lib/util/game/scene/Scene.h"
#include "application/platformer/entity/PlatformerPlayerEntity.h"
#include "application/platformer/text/PlatformerScoreText.h"
#include "lib/util/game/KeyListener.h"

class PlatformerScene1 : public Util::Game::Scene, public Util::Game::KeyListener {
public:
    PlatformerScene1() = default;

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


#endif //HHUOS_PLATFORMERSCENE1_H
