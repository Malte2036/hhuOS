//
// Created by malte on 05.12.22.
//

#include "GravityEntity.h"
#include "lib/util/math/Math.h"
#include "lib/util/log/Logger.h"

namespace Util::Game {

    const double friction = 1.5;

    GravityEntity::GravityEntity(const Vector2 position) : Entity(position) {}

    const double gravity = 0.1;
    const double groundY = -1;

    void GravityEntity::performTransformation(double frameTime) {
        if (position.getY() > (groundY + 0.05)) {
            force = force + calculateNewtonGravity();
        }
        if (force.length() != 0) {
            auto calculatedForce = force * frameTime;

            auto newPosition = position + calculatedForce;

            auto event = new TransformEvent(newPosition);
            onTransformEvent(event);

            if (!event->isCanceled()) {
                setPosition(newPosition);
                force = force - (calculatedForce * friction);

                if (force.length() <= 0.01) {
                    force = Vector2();
                }
            } else {
                force = Vector2();
            }
        }
    }

    Vector2 GravityEntity::calculateNewtonGravity() {
        auto groundPosition = Vector2(position.getX(), groundY);
        auto r2 = Math::Math::pow((groundPosition - position).length(), 2);

        auto m = groundPosition.mult(position);
        m = -1 * Math::Math::absolute(m);

        double gravityForce = gravity * (m / r2);

        return {0, gravityForce};
    }
}