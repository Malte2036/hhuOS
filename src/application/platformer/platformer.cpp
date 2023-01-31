//
// Created by malte on 07.12.22.
//



#include "lib/util/system/System.h"
#include "lib/util/graphic/LinearFrameBuffer.h"
#include "lib/util/game/Engine.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/log/Logger.h"
#include "PlatformerGame.h"
#include "application/platformer/scene/PlatformerScene1.h"
#include "lib/util/file/File.h"

int32_t main(int32_t argc, char *argv[]) {
    Logger::logMessage("Starting platformer game!");

    auto game = new PlatformerGame();
    auto engine = Util::Game::Engine::setup(*game);
    Util::Game::GameManager::setGame<PlatformerGame>(game);

    auto scene = new PlatformerScene1();

    engine->runWithScene(scene);
    return 0;
}
