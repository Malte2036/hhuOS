//
// Created by Malte Sehmer on 20.12.22.
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
        auto entity = getEntity();
        if (entity == nullptr) return;

        auto position = entity->getPosition();
        auto velocity = entity->getVelocity();
        if (Math::Math::absolute(position.getY() - groundY) > 0.01) {
            auto force = Vector2(0, mass * gravityValue);
            auto acceleration = Vector2(force.getX() / mass, force.getY() / mass);

            velocity = velocity + Vector2(acceleration.getX() * dt, acceleration.getY() * dt);
        }

        if (velocity.length() < 0.001) {
            return;
        }

        auto computedPosition = position + Vector2(velocity.getX() * dt, velocity.getY() * dt);

        auto event = TranslateEvent(computedPosition);
        entity->translateEvent(event);

        if (!event.isCanceled()) {
            //BUG: Null Pointer Exception wird hier irgendwie ausgelöst (Platformer: Ninja)
            entity->setPosition(computedPosition);

            velocity = Vector2(velocity.getX() * stopFactorX, velocity.getY());
        } else {
            velocity = Vector2();
        }

        entity->setVelocity(velocity);
    }
}