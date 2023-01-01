//
// Created by malte on 04.12.22.
//
#include "Entity.h"
#include "lib/util/game/entity/component/Component.h"


namespace Util::Game {

    Entity::Entity(const Memory::String tag, const Vector2 &position) : tag{tag}, position{position}, components() {}

    void Entity::translate(const Vector2 &vector2) {
        velocity = velocity + vector2;
    }

    void Entity::translateX(const double x) {
        velocity = Vector2(x, velocity.getY());
    }

    void Entity::translateY(const double y) {
        velocity = Vector2(velocity.getX(), y);
    }

    Memory::String Entity::getTag() const {
        return tag;
    }

    Vector2 Entity::getPosition() const {
        return position;
    }

    void Entity::setPosition(const Vector2 &vector2) {
        position = vector2;
    }

    Vector2 Entity::getVelocity() const {
        return velocity;
    }

    void Entity::setVelocity(const Vector2 &vector2) {
        velocity=vector2;
    }

    void Entity::addComponent(Component *component) {
        component->setEntity(this);
        components.add(component);
    }

    void Entity::update(double dt) {
        for (const auto &component: components){
            component->update(dt);
        }
        onUpdate(dt);
    }


}