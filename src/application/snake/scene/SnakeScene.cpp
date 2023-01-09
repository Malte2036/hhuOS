//
// Created by malte on 08.01.23.
//

#include "SnakeScene.h"
#include "../SnakeGame.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/game/entity/component/LinearMovementComponent.h"
#include "application/snake/entity/FoodEntity.h"
#include "lib/util/log/Logger.h"

void SnakeScene::init() {
    auto game = Util::Game::GameManager::getGame<SnakeGame>();
    game->setSnakeGameData({0});

    snake = new SnakeEntity(Vector2(0, 0), 0.1, Util::Graphic::Colors::MAGENTA, none, 0.02);
    snake->addComponent(new Util::Game::LinearMovementComponent());
    addEntity(snake);

    addEntity(new FoodEntity(Vector2(0.3, 0.4), 0.05));

    scoreText = new SnakeScoreText(Vector2(-1, 0.95), game->getSnakeGameData().score);
    addObject(scoreText);

    setKeyListener(*this);
}

void SnakeScene::drawInitialBackground(Util::Game::Graphics2D &graphics) {

}

void SnakeScene::onUpdate(double dt) {
    auto game = Util::Game::GameManager::getGame<SnakeGame>();

    snake->move();
    if (lastScore != game->getSnakeGameData().score) {
        scoreText->setScore(game->getSnakeGameData().score);
        lastScore = game->getSnakeGameData().score;
    }
}

void SnakeScene::keyPressed(char c) {
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
            Util::Game::GameManager::getGame<SnakeGame>()->stop();
            break;
        default:
            snake->setColor(Util::Graphic::Colors::RED);
    }
}
