//
// Created by malte on 04.12.22.
//
#include "Entity.h"


namespace Util::Game {

    Entity::Entity(const Vector2 &position) : position{position} {}

    void Entity::transform(const Vector2 &vector2) {
        auto newVector2 = position.add(vector2);

        auto event = new TransformEvent(newVector2);

        onTransformEvent(event);
        if (!event->isCanceled()) {
            setPosition(newVector2);
        }
    }

    Vector2 Entity::getPosition() const {
        return position;
    }

    void Entity::setPosition(const Vector2 &vector2) {
        position = vector2;
    }
}