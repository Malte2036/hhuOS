//
// Created by malte on 20.12.22.
//

#include "LinearMovementComponent.h"

namespace Util::Game {

    void LinearMovementComponent::update(double dt) {
        auto position = getEntity()->getPosition();
        auto velocity = getEntity()->getVelocity();

        auto newPosition = position.add(velocity);

        auto event = new TranslateEvent(newPosition);
        getEntity()->onTranslateEvent(event);

        if (!event->isCanceled()) {
            getEntity()->setPosition(newPosition);
        }
        getEntity()->setVelocity(Vector2());
    }
}