//
// Created by malte on 20.12.22.
//

#include "GravityComponent.h"
#include "lib/util/math/Math.h"

namespace Util::Game {


    GravityComponent::GravityComponent(const double groundY, const double mass, const double stopFactorX,
                                       const double gravityValue) : groundY{groundY}, mass{mass},
                                                                    stopFactorX{stopFactorX},
                                                                    gravityValue{gravityValue} {

    }

    void GravityComponent::update(double dt) {
        auto position = getEntity()->getPosition();
        auto velocity = getEntity()->getVelocity();
        if (Math::Math::absolute(position.getY() - groundY) > 0.01) {
            auto force = Vector2(0, mass * gravityValue);
            auto acceleration = Vector2(force.getX() / mass, force.getY() / mass);

            velocity = velocity + Vector2(acceleration.getX() * dt, acceleration.getY() * dt);
        }

        if (velocity.length() < 0.001) {
            return;
        }

        auto computedPosition = position + Vector2(velocity.getX() * dt, velocity.getY() * dt);

        auto event = new TranslateEvent(computedPosition);
        getEntity()->translateEvent(event);

        if (!event->isCanceled()) {
            getEntity()->setPosition(computedPosition);

            velocity = Vector2(velocity.getX() * stopFactorX, velocity.getY());
        } else {
            velocity = Vector2();
        }

        getEntity()->setVelocity(velocity);

    }
}