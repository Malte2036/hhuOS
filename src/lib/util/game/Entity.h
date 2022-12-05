//
// Created by malte on 04.12.22.
//
#ifndef HHUOS_ENTITY_H
#define HHUOS_ENTITY_H

#include "Drawable.h"
#include "lib/util/math/Vector2.h"
#include "lib/util/game/event/TransformEvent.h"
#include "lib/util/game/event/CollisionEvent.h"
#include "lib/util/game/collider/Collider.h"
#include "lib/util/game/collider/RectangleCollider.h"

namespace Util::Game {
    class Entity : public Drawable {
        friend class Game;

    public:
        explicit Entity(const Vector2 &position);

        void transform(const Vector2 &vector2);

        void transformX(const double x);

        void transformY(const double y);

        virtual void onTransformEvent(TransformEvent *event) = 0;

        virtual void onCollisionEvent(CollisionEvent *event) = 0;

        [[nodiscard]] Vector2 getPosition() const;

        void setPosition(const Vector2 &vector2);

        virtual Util::Game::RectangleCollider getCollider() const = 0;


    private:
        virtual void performTransformation(double frameTime);

    protected:
        Vector2 force = Vector2();
        Vector2 position;
    };

}

#endif //HHUOS_ENTITY_H
