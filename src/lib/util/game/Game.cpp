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
#include "lib/util/data/Pair.h"

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

        for (auto *entity: removeEntityList) {
            drawables.remove(entity);
            entities.remove(entity);
            delete entity;
        }

        addList.clear();
        removeList.clear();
        removeEntityList.clear();
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

    void Game::removeEntity(Entity *entity) {
        if (!removeEntityList.contains(entity)) {
            removeEntityList.add(entity);
        }
    }

    void Game::updateEntities(double frameTime) {
        for (Entity *entity: entities) {
            entity->update(frameTime);
        }
    }

    void Game::checkCollision() {
        auto detectedCollisions = Data::ArrayList<Data::Pair<Entity *, Entity *>>();
        for (Entity *entity: entities) {
            for (Entity *otherEntity: entities) {
                if (entity != otherEntity && !detectedCollisions.contains(createEntityPair(entity, otherEntity))) {
                    auto side = entity->getCollider().isColliding(otherEntity->getCollider());
                    if (side != NO_SIDE) {
                        entity->collisionEvent(new CollisionEvent(otherEntity, side));

                        RectangleCollidedSide otherSide;
                        switch (side) {
                            case RIGHT_SIDE:
                                otherSide = LEFT_SIDE;
                                break;
                            case LEFT_SIDE:
                                otherSide = RIGHT_SIDE;
                                break;
                            case TOP_SIDE:
                                otherSide = BOTTOM_SIDE;
                                break;
                            case BOTTOM_SIDE:
                                otherSide = TOP_SIDE;
                                break;
                            default:
                                otherSide = NO_SIDE;
                                break;
                        }

                        otherEntity->collisionEvent(new CollisionEvent(entity, otherSide));

                        detectedCollisions.add(createEntityPair(entity, otherEntity));
                    }
                }
            }
        }
    }

    Data::Pair<Entity *, Entity *> Game::createEntityPair(Entity *a, Entity *b) {
        if (a < b) {
            return {a, b};
        }
        return {b, a};
    }

    Camera *Game::getCamera() {
        return camera;
    }
}