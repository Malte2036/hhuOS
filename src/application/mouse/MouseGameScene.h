//
// Created by malte on 09.01.23.
//

#ifndef HHUOS_MOUSEGAMESCENE_H
#define HHUOS_MOUSEGAMESCENE_H

#include "lib/util/game/scene/Scene.h"
#include "MouseCursor.h"

class MouseGameScene : public Util::Game::Scene, public Util::Game::KeyListener {
private:
    void init() override;

    void onUpdate(double dt) override;

    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;

    void keyPressed(Util::Io::Key key) override;

    void keyReleased(Util::Io::Key key) override;

    MouseCursor *cursor = new MouseCursor();
};


#endif //HHUOS_MOUSEGAMESCENE_H
