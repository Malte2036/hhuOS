//
// Created by Malte Sehmer on 04.02.23.
//

#ifndef HHUOS_PLATFORMERSCENE_H
#define HHUOS_PLATFORMERSCENE_H


#include "lib/util/game/scene/Scene.h"
#include "application/platformer/entity/PlatformerPlayerEntity.h"
#include "application/platformer/text/PlatformerScoreText.h"

class PlatformerScene : public Util::Game::Scene, public Util::Game::KeyListener {
public:
    explicit PlatformerScene(const Util::Memory::String &sceneFilePath);

private:
    void init() override;

    void onUpdate(double dt) override;

    void keyPressed(Util::Io::Key key) override;

    void keyReleased(Util::Io::Key key) override;

private:
    const Util::Memory::String sceneFilePath;

    PlatformerPlayerEntity *player = nullptr;
    const double groundY = -2;

    PlatformerScoreText *scoreText = nullptr;
};


#endif //HHUOS_PLATFORMERSCENE_H
