//
// Created by malte on 07.12.22.
//

#include "MarioGame.h"

MarioGame::MarioGame() {
    player = new MarioEntity("Player", Vector2());
    addEntity(player);

    itemBlocks.add(new MarioItemBlockEntity("ItemBlock", Vector2(-0.2, 0.3)));
    itemBlocks.add(new MarioItemBlockEntity("ItemBlock", Vector2(-0.5, -0.6)));

    for(auto block:itemBlocks){
        addEntity(block);
    }

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
