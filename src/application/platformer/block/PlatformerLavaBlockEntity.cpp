//
// Created by Malte Sehmer on 01.02.23.
//

#include "PlatformerLavaBlockEntity.h"
#include "lib/util/game/GameManager.h"
#include "application/platformer/PlatformerGame.h"

PlatformerLavaBlockEntity::PlatformerLavaBlockEntity(const Vector2 &position, int countX, int countY)
        : PlatformerBlockEntity(
        "LavaBlock", position, "/initrd/game/platformer/ground/lava_middle.bmp", countX, countY) {

}

void PlatformerLavaBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    auto size = Util::Game::GameManager::getGame<PlatformerGame>()->getBlockSize();
    for (int y = 0; y < countY; ++y) {
        for (int x = 0; x < countX; ++x) {
            graphics.drawImage(Vector2(position.getX() + x * size, position.getY() + y * size), *sprite->getImage(),
                               flip);
        }
    }
}

void PlatformerLavaBlockEntity::onUpdate(double dt) {
    if (animateIndex % 30 == 0) {
        flip = !flip;
    }
    animateIndex = (animateIndex + 1) % 30;
}
