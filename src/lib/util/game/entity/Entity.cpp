//
// Created by malte on 04.12.22.
//
#include "Entity.h"
#include "lib/util/game/entity/component/Component.h"


namespace Util::Game {

    Entity::Entity(const Memory::String tag, const Vector2 &position, RectangleCollider *collider) : tag{tag},
                                                                                                     position{position},
                                                                                                     collider{collider},
                                                                                                     components() {}

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
        if(collider != nullptr){
            collider->setPosition(position);
        }
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
        for (const auto &component: components) {
            component->update(dt);
        }
        onUpdate(dt);
    }

    void Entity::translateEvent(TranslateEvent *event) {
        collider->lastPosition = position;
        onTranslateEvent(event);
    }

    void Entity::collisionEvent(CollisionEvent *event) {
        if (getCollider()->getColliderType() == DYNAMIC_COLLIDER) {
            switch (event->getRectangleCollidedSide()) {
                case BOTTOM_SIDE:
                    setPosition(Vector2(position.getX(), event->getCollidedWith()->getPosition().getY() +
                                                         event->getCollidedWith()->getCollider()->getHeight()));
                    if (velocity.getY() < 0) {
                        setVelocity(Vector2(velocity.getX(), 0));
                    }
                    break;
                case TOP_SIDE:
                    setPosition(Vector2(position.getX(),
                                        event->getCollidedWith()->getPosition().getY() - getCollider()->getHeight()));
                    if (velocity.getY() > 0) {
                        setVelocity(Vector2(velocity.getX(), 0));
                    }
                    break;
                case LEFT_SIDE:
                    setPosition(Vector2(event->getCollidedWith()->getPosition().getX() - getCollider()->getWidth(),
                                        position.getY()));
                    if (velocity.getX() < 0) {
                        setVelocity(Vector2(0, velocity.getY()));
                    }
                    break;
                case RIGHT_SIDE:
                    setPosition(Vector2(event->getCollidedWith()->getPosition().getX() +
                                        event->getCollidedWith()->getCollider()->getWidth(), position.getY()));
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