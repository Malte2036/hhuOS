/*
 * Copyright (C) 2018-2022 Heinrich-Heine-Universitaet Duesseldorf,
 * Institute of Computer Science, Department Operating Systems
 * Burak Akguel, Christian Gesse, Fabian Ruhland, Filip Krakowski, Michael Schoettner
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include "Game.h"
#include "GameManager.h"

#include "lib/util/game/Drawable.h"

namespace Util {
    namespace Game {
        class Graphics2D;

        class KeyListener;

        class MouseListener;
    }  // namespace Game
}  // namespace Util

namespace Util::Game {

    Game::~Game() {
        delete scene;
    }

    bool Game::isRunning() const {
        return running;
    }

    void Game::stop() {
        running = false;
    }

    Scene *Game::getScene() {
        return scene;
    }

    void Game::pushScene(Scene *newScene) {
        if (newScene == nullptr) return;

        scene = newScene;
        newScenePushed = true;
    }

    void Game::initScene(Graphics2D &graphics) {
        newScenePushed = false;

        scene->init();
        scene->drawInitialBackground(graphics);
        graphics.saveAsBackground();
    }

    bool Game::isNewScenePushed() const {
        return newScenePushed;
    }
}