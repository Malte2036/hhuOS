//
// Created by Malte Sehmer on 04.12.22.
//
#include "Entity.h"
#include "lib/util/game/entity/component/Component.h"


namespace Util::Game {

    Entity::Entity(const Memory::String &tag, const Vector2 &position, RectangleCollider *collider) : tag{tag},
                                                                                                      position{
                                                                                                              position},
                                                                                                      collider{
                                                                                                              collider},
                                                                                                      components() {}

    Entity::~Entity() {
        delete (collider);

        for (const auto *component: components) {
            delete (component);
        }
    }

    void Entity::translate(const Vector2 &vector2) {
        velocity = velocity + vector2;
    }

    void Entity::translateX(const double x) {
        velocity = Vector2(x, velocity.getY());
    }

    void Entity::translateY(const double y) {
        velocity = Vector2(velocity.getX(), y);
    }

    Memory::String Entity::getTag() const {
        return tag;
    }

    Vector2 Entity::getPosition() const {
        return position;
    }

    void Entity::setPosition(const Vector2 &vector2) {
        position = vector2;
        if (collider != nullptr) {
            collider->setPosition(position);
        }
        positionChanged = true;
    }

    Vector2 Entity::getVelocity() const {
        return velocity;
    }

    void Entity::setVelocity(const Vector2 &vector2) {
        velocity = vector2;
    }

    void Entity::addComponent(Component *component) {
        component->setEntity(this);
        components.add(component);
    }

    void Entity::update(double dt) {
        collider->lastPosition = position;
        positionChanged = false;

        for (const auto &component: components) {
            if (component == nullptr) continue;

            component->update(dt);
        }
        onUpdate(dt);
    }

    void Entity::translateEvent(TranslateEvent &event) {
        onTranslateEvent(event);
    }

    void Entity::collisionEvent(CollisionEvent &event) {
        if (collider == nullptr) return;

        if (collider->getColliderType() == DYNAMIC_COLLIDER) {
            switch (event.getRectangleCollidedSide()) {
                case BOTTOM_SIDE:
                    setPosition(Vector2(position.getX(), event.getCollidedWith().getPosition().getY() +
                                                         event.getCollidedWith().getCollider()->getHeight()));
                    if (velocity.getY() < 0) {
                        setVelocity(Vector2(velocity.getX(), 0));
                    }
                    break;
                case TOP_SIDE:
                    setPosition(Vector2(position.getX(),
                                        event.getCollidedWith().getPosition().getY() - collider->getHeight()));
                    if (velocity.getY() > 0) {
                        setVelocity(Vector2(velocity.getX(), 0));
                    }
                    break;
                case LEFT_SIDE:
                    setPosition(Vector2(event.getCollidedWith().getPosition().getX() +
                                        event.getCollidedWith().collider->getWidth(), position.getY()));
                    if (velocity.getX() < 0) {
                        setVelocity(Vector2(0, velocity.getY()));
                    }
                    break;
                case RIGHT_SIDE:
                    setPosition(Vector2(event.getCollidedWith().getPosition().getX() - collider->getWidth(),
                                        position.getY()));
                    if (velocity.getX() > 0) {
                        setVelocity(Vector2(0, velocity.getY()));
                    }
                    break;
            }
        }
        onCollisionEvent(event);
    }

    RectangleCollider *Entity::getCollider() const {
        return collider;
    }
}