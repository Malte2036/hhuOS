//
// Created by malte on 08.01.23.
//

#include "PlatformerScene2.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "application/platformer/block/PlatformerSolidBlockEntity.h"
#include "application/platformer/PlatformerGame.h"

void PlatformerScene2::init() {
    setKeyListener(*this);

    player = new PlatformerPlayerEntity("Player", Vector2(-0.2, 0), groundY);
    player->addComponent(new Util::Game::GravityComponent(groundY));
    addEntity(player);

    scoreText = new PlatformerScoreText(Vector2(-1, 0.95), 0);
    addObject(scoreText);

    auto game = Util::Game::GameManager::getGame<PlatformerGame>();
    game->spawnNinja(Vector2(1.15, groundY + 0.1), groundY);

    game->createSceneFromSceneFile(this, "/initrd/game/platformer/scene/scene2.txt");
}


void PlatformerScene2::drawInitialBackground(Util::Game::Graphics2D &graphics) {
    graphics.setBackgroundColor(Util::Graphic::Colors::HHU_BLUE);

    auto game = Util::Game::GameManager::getGame<PlatformerGame>();
    auto blockSize = game->getBlockSize();
    auto grassSprite = new Util::Game::Sprite("/initrd/game/platformer/ground/grass/ground_grass_middle.bmp", blockSize,
                                              blockSize);
    auto dirtSprite = new Util::Game::Sprite("/initrd/game/platformer/ground/dirt/ground_dirt_middle.bmp", blockSize,
                                             blockSize);

    auto res = Util::Game::GameManager::getResolution();
    double currentX = -res.getX() / 2 + 0.01;
    while (currentX < res.getX() / 2) {
        auto image = grassSprite->getImage();

        double currentY = groundY - blockSize;
        auto firstRow = true;
        while (currentY >= -res.getY() / 2) {
            graphics.drawImage(Vector2(currentX, currentY), *image);

            if (firstRow) {
                image = dirtSprite->getImage();
                firstRow = false;
            }
            currentY -= blockSize;
        }
        currentX += blockSize;
    }

    auto cloudSprite = new Util::Game::Sprite("/initrd/game/platformer/background/cloud.bmp", 0.3, 0.15);
    graphics.drawImage(Vector2(-(res.getX() / 2) + 0.25, (res.getY() / 2) - 0.2), *cloudSprite->getImage());
    graphics.drawImage(Vector2(-0.4, (res.getY() / 2) - 0.7), *cloudSprite->getImage());
    graphics.drawImage(Vector2(0.6, (res.getY() / 2) - 0.5), *cloudSprite->getImage());
    graphics.drawImage(Vector2(0.1, (res.getY() / 2) - 0.35), *cloudSprite->getImage());
}

double PlatformerScene2::getGroundY() const {
    return groundY;
}

void PlatformerScene2::onUpdate(double delta) {
    scoreText->increaseScore();
}

void PlatformerScene2::keyPressed(char c) {
    switch (c) {
        case 'a':
            player->moveLeft();
            return;
        case 'd':
            player->moveRight();
            return;
        case 'w':
            player->jump();
            return;
        case 'q':
            Util::Game::GameManager::getGame<PlatformerGame>()->stop();
            return;
    }
}