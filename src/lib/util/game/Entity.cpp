//
// Created by malte on 04.12.22.
//
#include "Entity.h"
#include "lib/util/log/Logger.h"


namespace Util::Game {

    Entity::Entity(const Vector2 &position) : position{position} {}

    void Entity::transform(const Vector2 &vector2) {
        force = force + vector2;
    }

    void Entity::transformX(const double x) {
        force = Vector2(x, force.getY());
    }

    void Entity::transformY(const double y) {
        force = Vector2(force.getX(), y);
    }

    Vector2 Entity::getPosition() const {
        return position;
    }

    void Entity::setPosition(const Vector2 &vector2) {
        position = vector2;
    }

    void Entity::performTransformation(double frameTime) {

        auto newPosition = position.add(force);

        auto event = new TransformEvent(newPosition);
        onTransformEvent(event);

        if (!event->isCanceled()) {
            setPosition(newPosition);
        }
        force = Vector2();
    }
}