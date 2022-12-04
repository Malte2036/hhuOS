//
// Created by malte on 04.12.22.
//

#include "DemoSprite.h"
#include "lib/util/system/System.h"

DemoSprite::DemoSprite(double initialX, double initialY, Util::Graphic::Color initialColor, DirectionType initialDirection) : Sprite(initialX, initialY, initialColor) {
    direction = initialDirection;
}

void DemoSprite::draw(Util::Game::Graphics2D &graphics) const {
    Sprite::draw(graphics);
}

DirectionType DemoSprite::getDirection() {
    return direction;
}

void DemoSprite::setDirection(DirectionType directionType) {
    direction = directionType;
}
