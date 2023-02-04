//
// Created by Malte Sehmer on 08.01.23.
//

#include "PlatformerScene1.h"
#include "lib/util/game/GameManager.h"

PlatformerScene1::PlatformerScene1() : PlatformerScene("/initrd/game/platformer/scene/scene1.txt") {

}


void PlatformerScene1::drawInitialBackground(Util::Game::Graphics2D &graphics) {
    graphics.setBackgroundColor(Util::Graphic::Colors::HHU_BLUE);

    auto res = Util::Game::GameManager::getResolution();

    auto cloudSprite = new Util::Game::Sprite("/initrd/game/platformer/background/cloud.bmp", 0.2, 0.1);
    graphics.drawImage(Vector2(-(res.getX() / 2) + 0.25, (res.getY() / 2) - 0.65), *cloudSprite->getImage());
    graphics.drawImage(Vector2(-0.25, -((res.getY() / 2) - 0.5)), *cloudSprite->getImage());
    graphics.drawImage(Vector2(0.6, (res.getY() / 2) - 0.7), *cloudSprite->getImage());
}