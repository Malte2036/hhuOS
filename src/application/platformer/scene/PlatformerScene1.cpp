//
// Created by malte on 08.01.23.
//

#include "PlatformerScene1.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "application/platformer/block/PlatformerBrickBlockEntity.h"
#include "application/platformer/block/PlatformerSolidBlockEntity.h"
#include "application/platformer/block/PlatformerItemBlockEntity.h"
#include "application/platformer/PlatformerGame.h"
#include "lib/util/stream/FileReader.h"

void PlatformerScene1::init() {
    setKeyListener(*this);

    player = new PlatformerPlayerEntity("Player", Vector2(-0.2, 0), groundY);
    player->addComponent(new Util::Game::GravityComponent(groundY));
    addEntity(player);

    scoreText = new PlatformerScoreText(Vector2(-1, 0.95), 0);
    addObject(scoreText);

    auto game = Util::Game::GameManager::getGame<PlatformerGame>();
    game->spawnNinja(Vector2(2, groundY + 0.1), groundY);

    game->createSceneFromSceneFile(this, "/initrd/game/platformer/scene/scene1.txt");
}


void PlatformerScene1::drawInitialBackground(Util::Game::Graphics2D &graphics) {
    graphics.setBackgroundColor(Util::Graphic::Colors::HHU_BLUE);

    auto game = Util::Game::GameManager::getGame<PlatformerGame>();
    auto blockSize = game->getBlockSize();
    auto grassSprite = new Util::Game::Sprite("/initrd/game/platformer/ground/grass/ground_grass_middle.bmp", blockSize,
                                              blockSize);
    auto dirtSprite = new Util::Game::Sprite("/initrd/game/platformer/ground/dirt/ground_dirt_middle.bmp", blockSize,
                                             blockSize);


    auto res = Util::Game::GameManager::getResolution();
    double currentX = -res.getX() / 2;
    while (currentX < res.getX() / 2) {
        auto image = grassSprite->getImage();

        double currentY = groundY - blockSize + 0.01;
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

    auto cloudSprite = new Util::Game::Sprite("/initrd/game/platformer/background/cloud.bmp", 0.2, 0.1);
    graphics.drawImage(Vector2(-(res.getX() / 2) + 0.25, (res.getY() / 2) - 0.65), *cloudSprite->getImage());
    graphics.drawImage(Vector2(-0.25, -((res.getY() / 2) - 0.5)), *cloudSprite->getImage());
    graphics.drawImage(Vector2(0.6, (res.getY() / 2) - 0.7), *cloudSprite->getImage());
}

double PlatformerScene1::getGroundY() const {
    return groundY;
}

void PlatformerScene1::onUpdate(double delta) {
    scoreText->increaseScore();
}

void PlatformerScene1::keyPressed(char c) {
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