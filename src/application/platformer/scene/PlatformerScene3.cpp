//
// Created by Malte Sehmer on 01.02.23.
//

#include "PlatformerScene3.h"

PlatformerScene3::PlatformerScene3() : PlatformerScene("/initrd/game/platformer/scene/scene3.txt") {

}

void PlatformerScene3::drawInitialBackground(Util::Game::Graphics2D &graphics) {
    graphics.setBackgroundColor(Util::Graphic::Colors::BLACK);
}