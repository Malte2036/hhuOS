//
// Created by malte on 05.12.22.
//

#include "GravityEntity.h"
#include "lib/util/math/Math.h"
#include "lib/util/log/Logger.h"

namespace Util::Game {

    const double friction = 1.5;

    GravityEntity::GravityEntity(const Memory::String &tag, const Vector2 &position, const double mass) : Entity(tag,
                                                                                                                 position),
                                                                                                          mass{mass} {}

    const double groundY = -1;
    const double gravityValue = -1;

    void GravityEntity::performTransformation(double frameTime) {
        if (position.getY() > (groundY + 0.025)) {
            auto force = Vector2(0, mass * gravityValue);
            auto acceleration = Vector2(force.getX() / mass, force.getY() / mass);

            velocity = velocity + Vector2(acceleration.getX() * frameTime, acceleration.getY() * frameTime);
        }

        auto computedPosition = position + Vector2(velocity.getX() * frameTime, velocity.getY() * frameTime);

        auto event = new TranslateEvent(computedPosition);
        onTranslateEvent(event);

        if (!event->isCanceled()) {
            setPosition(computedPosition);
        } else {
            velocity = Vector2();
        }
    }
}