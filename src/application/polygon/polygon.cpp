/*
 * Copyright (C) 2018-2022 Heinrich-Heine-Universitaet Duesseldorf,
 * Institute of Computer Science, Department Operating Systems
 * Burak Akguel, Christian Gesse, Fabian Ruhland, Filip Krakowski, Michael Schoettner
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <cstdint>
#include "lib/util/system/System.h"
#include "lib/util/graphic/LinearFrameBuffer.h"
#include "lib/util/game/Engine.h"
#include "PolygonDemo.h"
#include "lib/util/async/FunctionPointerRunnable.h"
#include "lib/util/async/Thread.h"
#include "PolygonDemoScene.h"
#include "lib/util/game/GameManager.h"

static const constexpr int32_t DEFAULT_COUNT = 10;

int32_t main(int32_t argc, char *argv[]) {
    auto count = argc > 1 ? Util::Memory::String::parseInt(argv[1]) : DEFAULT_COUNT;
    if (count < 0) {
        Util::System::error << "Polygon count must be greater than 0!";
        return -1;
    }

    auto game = new PolygonDemo();
    auto lfbFile = Util::File::File("/device/lfb");
    auto lfb = Util::Graphic::LinearFrameBuffer(lfbFile);

    auto engine = Util::Game::Engine(*game, lfb);

    Util::Game::GameManager::setGame<PolygonDemo>(game);

    auto scene = new PolygonDemoScene(count);

    engine.runWithScene(scene);
    return 0;
}