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
#include "lib/util/log/Logger.h"

namespace Util::Game {

    Game::~Game() {
        for (const auto *drawable: drawables) {
            delete drawable;
        }

        drawables.clear();
    }

    void Game::addObject(Drawable *drawable) {
        addList.add(drawable);
    }

    void Game::removeObject(Drawable *drawable) {
        removeList.add(drawable);
    }

    void Game::applyChanges() {
        for (auto *object: addList) {
            drawables.add(object);
        }

        for (auto *object: removeList) {
            drawables.remove(object);
            delete object;
        }

        addList.clear();
        removeList.clear();
    }

    void Game::draw(Graphics2D &graphics) {
        for (const auto *object: drawables) {
            object->draw(graphics);
        }
    }

    bool Game::isRunning() const {
        return running;
    }

    void Game::stop() {
        Game::running = false;
    }

    uint32_t Game::getObjectCount() const {
        return drawables.size();
    }

    void Game::setKeyListener(KeyListener &listener) {
        keyListener = &listener;
    }

    void Game::setMouseListener(MouseListener &listener) {
        mouseListener = &listener;
    }

    void Game::addEntity(Entity *entity) {
        addList.add(entity);
        entities.add(entity);
    }


    void Game::performEntityTranslations(double frameTime) {
        for (Entity *entity: entities) {
            entity->performTransformation(frameTime);
        }
    }

    void Game::checkCollision() {
        for (Entity *entity: entities) {
            for (Entity *otherEntity: entities) {
                if (entity != otherEntity) {
                    if (entity->getCollider().isColliding(otherEntity->getCollider())) {
                        entity->onCollisionEvent(new CollisionEvent(otherEntity->getTag()));
                    }
                }
            }
        }
    }
}