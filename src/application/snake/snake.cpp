//
// Created by Malte Sehmer on 05.12.22.
//


#include <cstdint>
#include "lib/util/system/System.h"
#include "lib/util/game/GameManager.h"
#include "SnakeGame.h"
#include "application/snake/scene/SnakeScene.h"
#include "lib/util/log/Logger.h"
#include "lib/util/file/File.h"

bool isRunning = true;

int32_t main(int32_t argc, char *argv[]) {
    Logger::logMessage("Starting SnakeGame");

    auto game = new SnakeGame();
    auto engine = Util::Game::Engine::setup(*game);
    Util::Game::GameManager::setGame<SnakeGame>(game);

    auto scene = new SnakeScene();

    engine->runWithScene(scene);
    return 0;
}
