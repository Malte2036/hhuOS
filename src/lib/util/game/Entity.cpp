//
// Created by malte on 04.12.22.
//
#include "Entity.h"
#include "lib/util/log/Logger.h"


namespace Util::Game {

    Entity::Entity(const Memory::String tag, const Vector2 &position) : tag{tag}, position{position} {}

    void Entity::translate(const Vector2 &vector2) {
        force = force + vector2;
    }

    void Entity::translateX(const double x) {
        force = Vector2(x, force.getY());
    }

    void Entity::translateY(const double y) {
        force = Vector2(force.getX(), y);
    }

    Memory::String Entity::getTag() const {
        return tag;
    }

    Vector2 Entity::getPosition() const {
        return position;
    }

    void Entity::setPosition(const Vector2 &vector2) {
        position = vector2;
    }

    void Entity::performTransformation(double frameTime) {

        auto newPosition = position.add(force);

        auto event = new TranslateEvent(newPosition);
        onTranslateEvent(event);

        if (!event->isCanceled()) {
            setPosition(newPosition);
        }
        force = Vector2();
    }
}