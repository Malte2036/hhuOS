//
// Created by Malte Sehmer on 04.02.23.
//

#include "PlatformerScene.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "lib/util/game/entity/component/LinearMovementComponent.h"
#include "application/platformer/PlatformerGame.h"
#include "application/platformer/entity/PlatformerPlayerProjectileEntity.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/log/Logger.h"

PlatformerScene::PlatformerScene(const Util::Memory::String &sceneFilePath) : sceneFilePath{sceneFilePath} {

}

void PlatformerScene::init() {
    setKeyListener(*this);

    player = new PlatformerPlayerEntity("Player", Vector2(-0.2, 0), groundY);
    player->addComponent(new Util::Game::GravityComponent(groundY));
    addEntity(player);

    scoreText = new PlatformerScoreText(Vector2(-1, 0.95), 0);
    addObject(scoreText);

    auto game = Util::Game::GameManager::getGame<PlatformerGame>();
    Logger::logMessage(sceneFilePath);
    game->createSceneFromSceneFile(this, sceneFilePath);
}

void PlatformerScene::onUpdate(double dt) {
    scoreText->increaseScore();

    if (moveLeft)
        player->moveLeft();
    if (moveRight)
        player->moveRight();
}

void PlatformerScene::keyPressed(Util::Io::Key key) {
    switch (key.getAscii()) {
        case 'a':
            moveLeft = true;
            return;
        case 'd':
            moveRight = true;
            return;
        case 'w':
            if (!moveJump) {
                moveJump = true;
                player->jump();
            }
            return;
        case 'q':
            Util::Game::GameManager::getGame<PlatformerGame>()->stop();
            return;
    }
    if (key.getScancode() == key.SPACE) {
        player->shoot();
        return;
    }
}

void PlatformerScene::keyReleased(Util::Io::Key key) {
    switch (key.getAscii()) {
        case 'a':
            moveLeft = false;
            return;
        case 'd':
            moveRight = false;
            return;
        case 'w':
            moveJump = false;
            return;
    }
}

