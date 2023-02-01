//
// Created by Malte Sehmer on 01.02.23.
//

#include "PlatformerScene3.h"
#include "lib/util/game/GameManager.h"
#include "application/platformer/PlatformerGame.h"
#include "lib/util/game/entity/component/GravityComponent.h"


void PlatformerScene3::init() {
    setKeyListener(*this);

    player = new PlatformerPlayerEntity("Player", Vector2(-0.2, 0), groundY);
    player->addComponent(new Util::Game::GravityComponent(groundY));
    addEntity(player);

    scoreText = new PlatformerScoreText(Vector2(-1, 0.95), 0);
    addObject(scoreText);

    auto game = Util::Game::GameManager::getGame<PlatformerGame>();

    game->createSceneFromSceneFile(this, "/initrd/game/platformer/scene/scene3.txt");
}


void PlatformerScene3::drawInitialBackground(Util::Game::Graphics2D &graphics) {
    graphics.setBackgroundColor(Util::Graphic::Colors::BLACK);
}

void PlatformerScene3::onUpdate(double delta) {
    scoreText->increaseScore();
}

void PlatformerScene3::keyPressed(Util::Io::Key key) {
    switch (key.getAscii()) {
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

void PlatformerScene3::keyReleased(Util::Io::Key key) {

}