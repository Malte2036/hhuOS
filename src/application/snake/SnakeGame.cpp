//
// Created by malte on 05.12.22.
//

#include "SnakeGame.h"
#include "lib/util/log/Logger.h"
#include "SnakeEntity.h"
#include "FoodEntity.h"
#include "lib/util/game/GameText.h"
#include "lib/util/game/entity/component/LinearMovementComponent.h"
#include "SnakeScoreText.h"

SnakeEntity *snake = nullptr;
SnakeScoreText *scoreText = nullptr;

SnakeGame::SnakeGame() {
    gameData = {0};

    snake = new SnakeEntity(Vector2(0, 0), 0.1, Util::Graphic::Colors::MAGENTA, none, 0.02);
    snake->addComponent(new Util::Game::LinearMovementComponent());
    addEntity(snake);

    addEntity(new FoodEntity(Vector2(0.3, 0.4), 0.05, &gameData));

    scoreText = new SnakeScoreText(Vector2(-1, 0.95), gameData.score);
    addObject(scoreText);

    setKeyListener(*this);

    Logger::logMessage("Starting SnakeGame");
}

int lastScore = 0;

void SnakeGame::update(double delta) {
    snake->move();
    if (lastScore != gameData.score) {
        scoreText->setScore(gameData.score);
        lastScore = gameData.score;
    }
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

void SnakeGame::drawInitialBackground(Util::Game::Graphics2D &graphics) {

}
