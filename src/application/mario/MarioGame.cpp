//
// Created by malte on 07.12.22.
//

#include "MarioGame.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "lib/util/game/GameManager.h"
#include "application/mario/entity/MarioGoombaEntity.h"
#include "application/mario/block/MarioBrickBlockEntity.h"
#include "application/mario/block/MarioSolidBlockEntity.h"

MarioGame::MarioGame() {
    player = new MarioEntity("Player", Vector2(-0.2, 0));
    player->addComponent(new Util::Game::GravityComponent(groundY));
    addEntity(player);

    scoreText = new MarioScoreText(Vector2(-1, 0.95), 0);
    addObject(scoreText);

    auto blockWidth = 0.078 + 0.001;

    addEntity(new MarioSolidBlockEntity(Vector2(blockWidth - 0.1, groundY)));

    addEntity(new MarioItemBlockEntity(Vector2(blockWidth * -3, groundY + 0.4)));
    addEntity(new MarioItemBlockEntity(Vector2(blockWidth * 2, groundY + 0.8)));

    addEntity(new MarioBrickBlockEntity(Vector2(0, groundY + 0.4)));

    addEntity(new MarioBrickBlockEntity(Vector2(blockWidth, groundY + 0.4)));
    addEntity(new MarioBrickBlockEntity(Vector2(blockWidth * 2, groundY + 0.4)));
    addEntity(new MarioBrickBlockEntity(Vector2(blockWidth * 3, groundY + 0.4)));
    addEntity(new MarioItemBlockEntity(Vector2(blockWidth * 4, groundY + 0.4)));
    addEntity(new MarioBrickBlockEntity(Vector2(blockWidth * 5, groundY + 0.4)));

    auto offsetX = blockWidth * 15;
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth, groundY + 0.4)));
    addEntity(new MarioItemBlockEntity(Vector2(offsetX + blockWidth * 2, groundY + 0.4)));
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth * 3, groundY + 0.4)));

    offsetX += blockWidth * 10;
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth, groundY + 0.8)));
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth * 2, groundY + 0.8)));
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth * 3, groundY + 0.8)));
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth * 4, groundY + 0.8)));
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth * 5, groundY + 0.8)));
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth * 6, groundY + 0.8)));
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth * 7, groundY + 0.8)));

    offsetX += blockWidth * 14;
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth, groundY + 0.8)));
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth * 2, groundY + 0.8)));
    addEntity(new MarioBrickBlockEntity(Vector2(offsetX + blockWidth * 3, groundY + 0.8)));
    addEntity(new MarioItemBlockEntity(Vector2(offsetX + blockWidth * 4, groundY + 0.8)));


    spawnGoomba(Vector2(1, -0.5));

    setKeyListener(*this);
}

void MarioGame::drawInitialBackground(Util::Game::Graphics2D &graphics) {
    graphics.setBackgroundColor(Util::Graphic::Colors::HHU_BLUE);

    auto blockSize = 0.078 + 0.001;
    auto grassSprite = new Util::Game::Sprite("/initrd/game/platformer/ground/grass/ground_grass_middle.bmp");
    auto dirtSprite = new Util::Game::Sprite("/initrd/game/platformer/ground/dirt/ground_dirt_middle.bmp");

    auto res = Util::Game::GameManager::getResolution();
    double currentX = -res.getX() / 2;
    while (currentX < res.getX() / 2) {
        auto image = grassSprite->getImage();

        double currentY = groundY - blockSize;
        auto firstRow = true;
        while (currentY >= -res.getY() / 2) {
            graphics.drawImage(Vector2(currentX, currentY), *image);

            if(firstRow){
                image = dirtSprite->getImage();
                firstRow = false;
            }
            currentY -= blockSize;
        }
        currentX += blockSize;
    }

    auto cloudSprite = new Util::Game::Sprite("/initrd/game/platformer/background/cloud.bmp");
    graphics.drawImage(Vector2(-(res.getX() / 2) + 0.25, (res.getY() / 2) - 0.65), *cloudSprite->getImage());
    graphics.drawImage(Vector2(-0.25, -((res.getY() / 2) - 0.5)), *cloudSprite->getImage());
    graphics.drawImage(Vector2(0.6, (res.getY() / 2) - 0.7), *cloudSprite->getImage());
}

void MarioGame::update(double delta) {
    scoreText->increaseScore();
}

void MarioGame::keyPressed(char c) {
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
            stop();
            return;
    }
}

void MarioGame::spawnGoomba(Vector2 position) {
    auto newGoomba = new MarioGoombaEntity(position + Vector2(1.5, 0));
    newGoomba->addComponent(new Util::Game::GravityComponent(groundY));
    addEntity(newGoomba);
}

double MarioGame::getGroundY() const {
    return groundY;
}
