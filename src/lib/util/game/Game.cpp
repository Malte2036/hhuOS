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
#include "lib/util/log/Logger.h"

namespace Util::Game {

    Game::~Game() {
        delete getScene();
    }

    void Game::addObject(Drawable *drawable) {
        Logger::logMessage("Old method addObject in Game used");
    }

    void Game::removeObject(Drawable *drawable) {
        Logger::logMessage("Old method removeObject in Game used");
    }

    bool Game::isRunning() const {
        return running;
    }

    void Game::stop() {
        Game::running = false;
    }

    void Game::setKeyListener(KeyListener &listener) {
    }

    void Game::setMouseListener(MouseListener &listener) {

    }

    void Game::addEntity(Entity *entity) {
        Logger::logMessage("Old method addEntity in Game used");
    }

    void Game::removeEntity(Entity *entity) {
        Logger::logMessage("Old method removeEntity in Game used");
    }

    Camera *Game::getCamera() {
        Logger::logMessage("Old method getCamera in Game used");
        return getScene()->getCamera();
    }

    Scene *Game::getScene() {
        return scene;
    }

    void Game::pushScene(Scene *newScene) {
        scene = newScene;
        scene->init();
    }
}