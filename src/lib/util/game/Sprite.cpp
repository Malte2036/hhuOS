//
// Created by malte on 04.12.22.
//
//#include "iostream"
#include "Sprite.h"


namespace Util::Game {

    Sprite::Sprite(double initialX, double initialY, Graphic::Color initialColor){
        //std::cout << "Sprite constructor called!";
        x = initialX;
        y = initialY;
        color = initialColor;
    }

    void Sprite::draw(Graphics2D &graphics) const {
        graphics.setColor(color);
        graphics.drawSquare(x, y, 0.1);
    }

    void Sprite::transform(double xTransform, double yTransform) {
        x += xTransform;
        y += yTransform;
    }

    double Sprite::getX() {
        return x;
    }

    double Sprite::getY() {
        return y;
    }

    void Sprite::setColor(Graphic::Color newColor) {
        color = newColor;
    }
}