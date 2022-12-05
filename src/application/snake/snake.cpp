//
// Created by malte on 05.12.22.
//


#include <cstdint>
#include "lib/util/system/System.h"
#include "lib/util/graphic/LinearFrameBuffer.h"
#include "lib/util/game/Engine.h"
#include "SnakeGame.h"

bool isRunning = true;

int32_t main(int32_t argc, char *argv[]) {
    Util::System::out << "Starting test...\n";

    auto lfbFile = Util::File::File("/device/lfb");
    auto lfb = Util::Graphic::LinearFrameBuffer(lfbFile);

    auto game = SnakeGame();
    auto engine = Util::Game::Engine(game, lfb);

    engine.run();
    return 0;
}
