//
// Created by Malte Sehmer on 08.01.23.
//

#ifndef HHUOS_TESTDEMOSCENE_H
#define HHUOS_TESTDEMOSCENE_H

#include "lib/util/game/scene/Scene.h"
#include "DemoEntity.h"

class TestDemoScene : public Util::Game::Scene, public Util::Game::KeyListener {
public:
    TestDemoScene() = default;
private:
    void init() override;

    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;

    void onUpdate(double dt) override;

public:
    void keyPressed(Util::Io::Key key) override;

    void keyReleased(Util::Io::Key key) override;

private:

    DemoEntity *player = nullptr;
};


#endif //HHUOS_TESTDEMOSCENE_H
