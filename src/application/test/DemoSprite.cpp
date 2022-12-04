//
// Created by malte on 04.12.22.
//

#include "DemoSprite.h"
#include "lib/util/system/System.h"

DemoSprite::DemoSprite(double initialX, double initialY, Util::Graphic::Color initialColor) : Sprite(initialX, initialY, initialColor) {
    Util::System::out << "Creating DemoSprite\n";
}

void DemoSprite::draw(Util::Game::Graphics2D &graphics) const {
    Sprite::draw(graphics);
}
