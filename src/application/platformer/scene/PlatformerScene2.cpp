//
// Created by Malte Sehmer on 08.01.23.
//

#include "PlatformerScene2.h"
#include "lib/util/game/GameManager.h"

PlatformerScene2::PlatformerScene2() : PlatformerScene("/initrd/game/platformer/scene/scene2.txt") {

}

void PlatformerScene2::drawInitialBackground(Util::Game::Graphics2D &graphics) {
    graphics.setBackgroundColor(Util::Graphic::Colors::HHU_BLUE);

    auto res = Util::Game::GameManager::getResolution();

    auto cloudSprite = new Util::Game::Sprite("/initrd/game/platformer/background/cloud.bmp", 0.3, 0.15);
    graphics.drawImage(Vector2(-(res.getX() / 2) + 0.25, (res.getY() / 2) - 0.2), *cloudSprite->getImage());
    graphics.drawImage(Vector2(-0.4, (res.getY() / 2) - 0.7), *cloudSprite->getImage());
    graphics.drawImage(Vector2(0.6, (res.getY() / 2) - 0.5), *cloudSprite->getImage());
    graphics.drawImage(Vector2(0.1, (res.getY() / 2) - 0.35), *cloudSprite->getImage());
}