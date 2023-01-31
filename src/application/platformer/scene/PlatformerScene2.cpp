//
// Created by Malte Sehmer on 08.01.23.
//

#include "PlatformerScene2.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "application/platformer/block/PlatformerSolidBlockEntity.h"
#include "application/platformer/PlatformerGame.h"

void PlatformerScene2::init() {
    setKeyListener(*this);

    player = new PlatformerPlayerEntity("Player", Vector2(-0.2, 0), groundY);
    player->addComponent(new Util::Game::GravityComponent(groundY));
    addEntity(player);

    scoreText = new PlatformerScoreText(Vector2(-1, 0.95), 0);
    addObject(scoreText);

    auto game = Util::Game::GameManager::getGame<PlatformerGame>();

    game->createSceneFromSceneFile(this, "/initrd/game/platformer/scene/scene2.txt");
}


void PlatformerScene2::drawInitialBackground(Util::Game::Graphics2D &graphics) {
    graphics.setBackgroundColor(Util::Graphic::Colors::HHU_BLUE);

    auto res = Util::Game::GameManager::getResolution();

    auto cloudSprite = new Util::Game::Sprite("/initrd/game/platformer/background/cloud.bmp", 0.3, 0.15);
    graphics.drawImage(Vector2(-(res.getX() / 2) + 0.25, (res.getY() / 2) - 0.2), *cloudSprite->getImage());
    graphics.drawImage(Vector2(-0.4, (res.getY() / 2) - 0.7), *cloudSprite->getImage());
    graphics.drawImage(Vector2(0.6, (res.getY() / 2) - 0.5), *cloudSprite->getImage());
    graphics.drawImage(Vector2(0.1, (res.getY() / 2) - 0.35), *cloudSprite->getImage());
}

double PlatformerScene2::getGroundY() const {
    return groundY;
}

void PlatformerScene2::onUpdate(double delta) {
    scoreText->increaseScore();
}

void PlatformerScene2::keyPressed(Util::Io::Key key) {
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

void PlatformerScene2::keyReleased(Util::Io::Key key) {

}