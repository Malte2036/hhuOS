//
// Created by malte on 04.12.22.
//
#include "Entity.h"
#include "lib/util/log/Logger.h"


namespace Util::Game {

    const double friction = 1.5;

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
        if (!(force.getX() == 0 && force.getY() == 0)) {
            Logger::logMessage(Util::Memory::String::format("frameTime: 0.%04u", frameTime));
            auto calculatedForce = force * frameTime;

            auto newPosition = position.add(calculatedForce);

            auto event = new TransformEvent(newPosition);
            onTransformEvent(event);
            
            if (!event->isCanceled()) {
                setPosition(newPosition);
                force = force - (calculatedForce * friction);

                if (!(force.getX() > 0.01 || force.getX() < -0.01)) {
                    force = Vector2();
                }
            } else {
                force = Vector2();
            }
        }
    }
}