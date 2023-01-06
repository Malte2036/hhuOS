//
// Created by malte on 07.12.22.
//



#include <cstdint>
#include "lib/util/system/System.h"
#include "lib/util/graphic/LinearFrameBuffer.h"
#include "lib/util/game/Engine.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/log/Logger.h"
#include "MarioGame.h"

bool isRunning = true;

int32_t main(int32_t argc, char *argv[]) {
    Logger::logMessage("Starting mario game!");

    auto lfbFile = Util::File::File("/device/lfb");
    auto lfb = Util::Graphic::LinearFrameBuffer(lfbFile);

    auto game = new MarioGame();
    auto engine = Util::Game::Engine(*game, lfb);

    Util::Game::GameManager::setGame<MarioGame>(game);

    engine.run();
    return 0;
}
