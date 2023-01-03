//
// Created by malte on 20.12.22.
//

#include "GravityComponent.h"

namespace Util::Game {

    const double groundY = -1;
    const double gravityValue = -1;
    const double stopFactorX = 0.9;

    const double mass = 1;

    void GravityComponent::update(double dt) {
        auto position = getEntity()->getPosition();
        auto velocity = getEntity()->getVelocity();
        if (position.getY() > (groundY + 0.025)) {
            auto force = Vector2(0, mass * gravityValue);
            auto acceleration = Vector2(force.getX() / mass, force.getY() / mass);

            velocity = velocity + Vector2(acceleration.getX() * dt, acceleration.getY() * dt);
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