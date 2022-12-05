//
// Created by malte on 04.12.22.
//
#include "Entity.h"


namespace Util::Game {

    Entity::Entity(Vector2 position, double size, Graphic::Color color) : position{position}, size{size},
                                                                          color{color} {}

    void Entity::draw(Graphics2D &graphics) const {
        graphics.setColor(color);
        graphics.drawSquare(position.getX(), position.getY(), size);
    }

    void Entity::transform(Vector2 vector2) {
        auto newVector2 = position.add(vector2);
        setPosition(newVector2);

        onTransformEvent(newVector2);
    }

    void Entity::setColor(Graphic::Color newColor) {
        color = newColor;
    }

    Vector2 Entity::getPosition() {
        return position;
    }

    void Entity::setPosition(Vector2 vector2) {
        position = vector2;
    }

    double Entity::getSize() {
        return size;
    }
}