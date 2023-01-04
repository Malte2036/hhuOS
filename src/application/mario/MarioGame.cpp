//
// Created by malte on 07.12.22.
//

#include "MarioGame.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "application/mario/entity/MarioGoombaEntity.h"
#include "application/mario/block/MarioBrickBlockEntity.h"

MarioGame::MarioGame() {
    player = new MarioEntity("Player", Vector2(-0.2, 0));
    player->addComponent(new Util::Game::GravityComponent(groundY));
    addEntity(player);

    auto blockWidth = 0.078;

    addEntity(new MarioItemBlockEntity(Vector2(blockWidth * -3, groundY + 0.4)));
    addEntity(new MarioItemBlockEntity(Vector2(blockWidth * 2, groundY + 0.8)));

    addEntity(new MarioBrickBlockEntity(Vector2(0, groundY + 0.4)));

    addEntity(new MarioBrickBlockEntity(Vector2(blockWidth, groundY + 0.4)));
    addEntity(new MarioBrickBlockEntity(Vector2(blockWidth * 2, groundY + 0.4)));
    addEntity(new MarioBrickBlockEntity(Vector2(blockWidth * 3, groundY + 0.4)));
    addEntity(new MarioItemBlockEntity(Vector2(blockWidth * 4, groundY + 0.4)));
    addEntity(new MarioBrickBlockEntity(Vector2(blockWidth * 5, groundY + 0.4)));

    spawnGoomba(Vector2(1, -0.5));


    setKeyListener(*this);
}

void MarioGame::update(double delta) {

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

const double MarioGame::getGroundY() {
    return groundY;
}
