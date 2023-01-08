//
// Created by malte on 05.12.22.
//

#include "SnakeGame.h"
#include "lib/util/log/Logger.h"
#include "application/snake/entity/SnakeEntity.h"
#include "application/snake/entity/FoodEntity.h"
#include "lib/util/game/GameText.h"
#include "lib/util/game/entity/component/LinearMovementComponent.h"
#include "application/snake/text/SnakeScoreText.h"

SnakeGame::SnakeGame() {

}
void SnakeGame::update(double dt) {

}

SnakeGameData SnakeGame::getSnakeGameData() {
    return gameData;
}

void SnakeGame::setSnakeGameData(SnakeGameData value) {
    gameData = value;
}