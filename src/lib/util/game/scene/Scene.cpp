//
// Created by malte on 08.01.23.
//

#include "Scene.h"
#include "lib/util/game/Game.h"

namespace Util::Game {

    Scene::~Scene() {
        for (const auto *drawable: drawables) {
            delete drawable;
        }

        drawables.clear();
    }

    void Scene::setKeyListener(KeyListener &listener) {
        keyListener = &listener;
    }

    void Scene::setMouseListener(MouseListener &listener) {
        mouseListener = &listener;
    }

    Camera *Scene::getCamera() {
        return camera;
    }

    void Scene::addEntity(Entity *entity) {
        addList.add(entity);
        entities.add(entity);
    }

    void Scene::removeEntity(Entity *entity) {

        if (!removeEntityList.contains(entity)) {
            removeEntityList.add(entity);
        }
    }

    uint32_t Scene::getObjectCount() const {
        return drawables.size();
    }

    void Scene::applyChanges() {
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

    void Scene::draw(Graphics2D &graphics) {
        for (const auto *object: drawables) {
            object->draw(graphics);
        }
    }

    void Scene::addObject(Drawable *drawable) {
        addList.add(drawable);
    }

    void Scene::removeObject(Drawable *drawable) {
        removeList.add(drawable);
    }

    void Scene::updateEntities(double dt) {
        for (Entity *entity: entities) {
            entity->update(dt);
        }
    }

    void Scene::checkCollision() {
        auto detectedCollisions = Data::ArrayList<Data::Pair<Entity *, Entity *>>();
        for (Entity *entity: entities) {
            if (entity->getTag() != "Player") {
                break;
            }
            if (entity->positionChanged) {
                for (Entity *otherEntity: entities) {
                    if (entity != otherEntity && !detectedCollisions.contains(createEntityPair(entity, otherEntity))) {
                        auto polyCol = entity->getPolygonCollider();
                        auto otherPolyCol = otherEntity->getPolygonCollider();
                        if (polyCol != nullptr && otherPolyCol != nullptr) {
                            auto isColliding = polyCol->isColliding(*otherPolyCol);
                            if (isColliding) {
                                auto side = BOTTOM_SIDE;
                                //entity->collisionEvent(new CollisionEvent(*otherEntity, side));
                                detectedCollisions.add(createEntityPair(entity, otherEntity));
                            }
                            break;
                        }
                    }
                    /*if (entity != otherEntity && !detectedCollisions.contains(createEntityPair(entity, otherEntity))) {
                        auto side = entity->getCollider()->isColliding(*otherEntity->getCollider());
                        if (side != NO_SIDE) {
                            entity->collisionEvent(new CollisionEvent(*otherEntity, side));

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

                            otherEntity->collisionEvent(new CollisionEvent(*entity, otherSide));

                            detectedCollisions.add(createEntityPair(entity, otherEntity));
                        }
                    }*/
                }
            }
        }
    }

    void Scene::update(float dt) {
        onUpdate(dt);
    }

    Data::Pair<Entity *, Entity *> Scene::createEntityPair(Entity *a, Entity *b) {
        if (a < b) {
            return {a, b};
        }
        return {b, a};
    }
}