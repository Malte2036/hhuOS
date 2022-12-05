//
// Created by malte on 05.12.22.
//

#include "GravityEntity.h"
#include "lib/util/log/Logger.h"

namespace Util::Game {

    const double friction = 1.5;

    GravityEntity::GravityEntity(const Vector2 position) : Entity(position) {}

    void GravityEntity::performTransformation(double frameTime) {
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