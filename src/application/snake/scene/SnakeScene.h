//
// Created by malte on 08.01.23.
//

#ifndef HHUOS_SNAKESCENE_H
#define HHUOS_SNAKESCENE_H

#include "lib/util/game/scene/Scene.h"
#include "application/snake/text/SnakeScoreText.h"
#include "application/snake/entity/SnakeEntity.h"

class SnakeScene : public Util::Game::Scene, public Util::Game::KeyListener  {
public:
    SnakeScene() = default;

private:
    void init() override;

    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;

    void update(double dt) override;

    void keyPressed(char c) override;

    SnakeEntity *snake = nullptr;
    SnakeScoreText *scoreText = nullptr;

    int lastScore = 0;
};


#endif //HHUOS_SNAKESCENE_H
