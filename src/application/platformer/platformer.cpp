//
// Created by malte on 07.12.22.
//



#include "lib/util/system/System.h"
#include "lib/util/graphic/LinearFrameBuffer.h"
#include "lib/util/game/Engine.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/log/Logger.h"
#include "PlatformerGame.h"
#include "application/platformer/scene/PlatformerScene.h"

bool isRunning = true;

int32_t main(int32_t argc, char *argv[]) {
    Logger::logMessage("Starting platformer game!");

    auto lfbFile = Util::File::File("/device/lfb");
    auto lfb = Util::Graphic::LinearFrameBuffer(lfbFile);

    auto game = new PlatformerGame();
    auto engine = Util::Game::Engine(*game, lfb);

    Util::Game::GameManager::setGame<PlatformerGame>(game);

    auto scene = new PlatformerScene();

    engine.runWithScene(scene);
    return 0;
}
