//
// Created by Malte Sehmer on 01.02.23.
//

#ifndef HHUOS_PLATFORMERSCENE3_H
#define HHUOS_PLATFORMERSCENE3_H


#include "application/platformer/entity/PlatformerPlayerEntity.h"
#include "application/platformer/text/PlatformerScoreText.h"
#include "lib/util/io/Key.h"
#include "lib/util/game/scene/Scene.h"
#include "PlatformerScene.h"

class PlatformerScene3 : public PlatformerScene {
public:
    PlatformerScene3();

private:
    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;
};

#endif //HHUOS_PLATFORMERSCENE3_H
