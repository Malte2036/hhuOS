//
// Created by Malte Sehmer on 08.01.23.
//

#ifndef HHUOS_PLATFORMERSCENE2_H
#define HHUOS_PLATFORMERSCENE2_H

#include "lib/util/game/scene/Scene.h"
#include "application/platformer/entity/PlatformerPlayerEntity.h"
#include "application/platformer/text/PlatformerScoreText.h"
#include "lib/util/game/KeyListener.h"
#include "PlatformerScene.h"

class PlatformerScene2 : public PlatformerScene{
public:
    PlatformerScene2();

private:
    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;
};


#endif //HHUOS_PLATFORMERSCENE2_H
