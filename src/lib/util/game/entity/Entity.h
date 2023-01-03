//
// Created by malte on 04.12.22.
//
#ifndef HHUOS_ENTITY_H
#define HHUOS_ENTITY_H

#include "lib/util/game/Drawable.h"
#include "lib/util/math/Vector2.h"
#include "lib/util/game/entity/event/TranslateEvent.h"
#include "lib/util/game/entity/event/CollisionEvent.h"
#include "lib/util/game/entity/collider/Collider.h"
#include "lib/util/game/entity/collider/RectangleCollider.h"
#include "lib/util/data/ArrayList.h"

namespace Util::Game {
    class Component;

    class Entity : public Drawable {
        friend class Game;
        friend class GravityComponent;
        friend class LinearMovementComponent;

    public:
        explicit Entity(Memory::String tag, const Vector2 &position);

        virtual void onUpdate(double dt) = 0;

        void translate(const Vector2 &vector2);

        void translateX(double x);

        void translateY(double y);

        virtual void onTranslateEvent(TranslateEvent *event) = 0;

        virtual void onCollisionEvent(CollisionEvent *event) = 0;

        [[nodiscard]] Memory::String getTag() const;

        [[nodiscard]] Vector2 getPosition() const;

        void setPosition(const Vector2 &vector2);

        [[nodiscard]] Vector2 getVelocity() const;

        void setVelocity(const Vector2 &vector2);

        virtual Util::Game::RectangleCollider getCollider() const = 0;

        void addComponent(Component *component);


    private:
        void update(double dt);
        void translateEvent(TranslateEvent *event);
        void collisionEvent(CollisionEvent *event);

    protected:
        Vector2 velocity = Vector2();
        Memory::String tag;
        Vector2 position;

        Data::ArrayList<Component*> components;
    };

}

#endif //HHUOS_ENTITY_H
