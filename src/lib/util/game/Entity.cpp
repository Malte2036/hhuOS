//
// Created by malte on 04.12.22.
//
//#include "iostream"
#include "Entity.h"


namespace Util::Game {

    Entity::Entity(double initialX, double initialY, Graphic::Color initialColor) {
        //std::cout << "Entity constructor called!";
        x = initialX;
        y = initialY;
        color = initialColor;
    }

    void Entity::draw(Graphics2D &graphics) const {
        graphics.setColor(color);
        graphics.drawSquare(x, y, 0.1);
    }

    void Entity::transform(double xTransform, double yTransform) {
        x += xTransform;
        y += yTransform;

        if (x > 1) {
            x = 1;
        } else if (x < -1) {
            x = -1;
        }

        if (y > (1 - 0.1)) {
            y = (1 - 0.1);
        } else if (y < -1) {
            y = -1;
        }
    }

    double Entity::getX() {
        return x;
    }

    double Entity::getY() {
        return y;
    }

    void Entity::setColor(Graphic::Color newColor) {
        color = newColor;
    }
}