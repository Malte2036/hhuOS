//
// Created by malte on 08.01.23.
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

    void update(double dt) override;

    void keyPressed(char c) override;

    DemoEntity *player = nullptr;
};


#endif //HHUOS_TESTDEMOSCENE_H
