//
// Created by Malte Sehmer on 08.01.23.
//

#ifndef HHUOS_PLATFORMERSCENE1_H
#define HHUOS_PLATFORMERSCENE1_H

#include "lib/util/game/scene/Scene.h"
#include "application/platformer/entity/PlatformerPlayerEntity.h"
#include "application/platformer/text/PlatformerScoreText.h"
#include "lib/util/game/KeyListener.h"
#include "PlatformerScene.h"

class PlatformerScene1 : public PlatformerScene {
public:
    PlatformerScene1();

private:
    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;
};


#endif //HHUOS_PLATFORMERSCENE1_H
