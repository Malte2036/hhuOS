//
// Created by malte on 05.12.22.
//

#include "SnakeGame.h"
#include "SnakeEntity.h"
#include "lib/util/log/Logger.h"

SnakeEntity *snake = nullptr;

SnakeGame::SnakeGame() {
    snake = new SnakeEntity(Vector2(0,0), 0.3, Util::Graphic::Colors::MAGENTA, none, 0.04);
    addObject(snake);

    setKeyListener(*this);

    Logger::logMessage("Starting SnakeGame");
}

void SnakeGame::update(double delta) {
    snake->move();
}

void SnakeGame::keyPressed(char c) {
    switch (c) {
        case 'w':
            snake->setDirection(up);
            break;
        case 'a':
            snake->setDirection(left);
            break;
        case 's':
            snake->setDirection(down);
            break;
        case 'd':
            snake->setDirection(right);
            break;
        case 'q':
            stop();
            break;
        default:
            snake->setColor(Util::Graphic::Colors::RED);
    }
}
