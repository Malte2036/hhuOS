//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_PLATFORMERGAME_H
#define HHUOS_PLATFORMERGAME_H

#include "lib/util/game/Game.h"
#include "entity/PlatformerPlayerEntity.h"
#include "block/PlatformerItemBlockEntity.h"
#include "text/PlatformerScoreText.h"

class PlatformerGame : public Util::Game::Game, public Util::Game::KeyListener {

public:
    PlatformerGame();

    void update(double delta) override;

    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;

    void keyPressed(char c) override;

    void spawnNinja(Vector2 position);

    [[nodiscard]] double getGroundY() const;

private:
    PlatformerPlayerEntity *player = nullptr;
    const double groundY = -0.75;

    PlatformerScoreText *scoreText = nullptr;
};

#endif //HHUOS_PLATFORMERGAME_H
