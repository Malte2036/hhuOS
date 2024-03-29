//
// Created by Malte Sehmer on 04.12.22.
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

        friend class Scene;

        friend class GravityComponent;

        friend class LinearMovementComponent;

    public:
        /**
         *
         * @param tag Freely selectable name or type of an entity. For later identification of the entity.
         * @param position initial position of the entity
         * @param collider collider of the entity (can be omitted)
         */
        explicit Entity(const Memory::String &tag, const Vector2 &position, RectangleCollider *collider = nullptr);

        /**
         * Copy Constructor.
         */
        Entity(const Entity &other) = delete;

        /**
         * Assignment operator.
         */
        Entity &operator=(const Entity &other) = delete;

        /**
        * Destructor.
        */
        ~Entity() override;

        /**
         * this function is called every frame
         * @param dt
         */
        virtual void onUpdate(double dt) = 0;

        /**
         * move the entity relatively in the direction of the vector
         * @param vector2
         */
        void translate(const Vector2 &vector2);

        /**
         * move the entity by x in x-direction
         * @param x
         */
        void translateX(double x);

        /**
         * move the entity by y in y-direction
         * @param y
         */
        void translateY(double y);

        [[nodiscard]] Memory::String getTag() const;

        [[nodiscard]] Vector2 getPosition() const;

        /**
         * set the position of the entity
         * @param vector2
         */
        void setPosition(const Vector2 &vector2);

        [[nodiscard]] Vector2 getVelocity() const;

        void setVelocity(const Vector2 &vector2);

        [[nodiscard]] RectangleCollider *getCollider() const;

        /**
         * call this function, to add Components to this Entity. For example the GravityComponent.
         * @param component
         */
        void addComponent(Component *component);


    protected:
        virtual void init() = 0;

        /**
         * every time translate(...), translateX(...) or translateY(...) is called, this function is automatically triggered. If the event is canceled (event→setCanceled(true)), the entity will not be translated.
         * @param event
         */
        virtual void onTranslateEvent(TranslateEvent &event) = 0;

        /**
         * is called when the collider of this entity overlaps with another collider.
         * @param event
         */
        virtual void onCollisionEvent(CollisionEvent &event) = 0;


    private:
        void update(double dt);

        void translateEvent(TranslateEvent &event);

        void collisionEvent(CollisionEvent &event);

        bool positionChanged = false;

    protected:
        Vector2 velocity = Vector2();
        Memory::String tag;
        Vector2 position;

        RectangleCollider *collider;

        Data::ArrayList<Component *> components;
    };

}

#endif //HHUOS_ENTITY_H
