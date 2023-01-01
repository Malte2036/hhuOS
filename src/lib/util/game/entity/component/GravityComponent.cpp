//
// Created by malte on 20.12.22.
//

#include "GravityComponent.h"

namespace Util::Game {

    const double groundY = -1;
    const double gravityValue = -1;

    const double mass = 1;

    void GravityComponent::update(double dt) {
        auto position = getEntity()->getPosition();
        auto velocity = getEntity()->getVelocity();
        if (position.getY() > (groundY + 0.025)) {
            auto force = Vector2(0, mass * gravityValue);
            auto acceleration = Vector2(force.getX() / mass, force.getY() / mass);

            getEntity()->setVelocity(velocity + Vector2(acceleration.getX() * dt, acceleration.getY() * dt));
        }

        auto computedPosition = position + Vector2(velocity.getX() * dt, velocity.getY() * dt);

        auto event = new TranslateEvent(computedPosition);
        getEntity()->onTranslateEvent(event);

        if (!event->isCanceled()) {
            getEntity()->setPosition(computedPosition);
        } else {
            getEntity()->setVelocity(Vector2());
        }

    }
}