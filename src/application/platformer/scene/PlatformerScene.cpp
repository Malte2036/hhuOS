//
// Created by Malte Sehmer on 04.02.23.
//

#include "PlatformerScene.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "application/platformer/PlatformerGame.h"
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
}

void PlatformerScene::keyPressed(Util::Io::Key key) {
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

void PlatformerScene::keyReleased(Util::Io::Key key) {

}

