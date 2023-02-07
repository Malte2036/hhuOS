//
// Created by Malte Sehmer on 20.12.22.
//

#include "LinearMovementComponent.h"

namespace Util::Game {

    void LinearMovementComponent::update(double dt) {
        auto position = getEntity()->getPosition();
        auto velocity = getEntity()->getVelocity();

        auto newPosition = position + velocity * dt;

        auto event = TranslateEvent(newPosition);
        getEntity()->translateEvent(event);

        if (!event.isCanceled()) {
            getEntity()->setPosition(newPosition);
        }
        getEntity()->setVelocity(Vector2());
    }
}