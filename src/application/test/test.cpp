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

#include "lib/util/system/System.h"
#include "lib/util/log/Logger.h"
#include "lib/util/stream/BufferedReader.h"
#include "lib/util/file/image/Image.h"
#include "lib/util/file/bmp/BMP.h"
#include "TestDemo.h"
#include "lib/util/game/Engine.h"
#include "lib/util/game/GameManager.h"

bool isRunning = true;

Util::Graphic::LinearFrameBuffer *lfb = nullptr;

int32_t main(int32_t argc, char *argv[]) {
    auto lfbFile = Util::File::File("/device/lfb");
    lfb = new Util::Graphic::LinearFrameBuffer(lfbFile);

    auto game = new TestDemo();
    auto engine = Util::Game::Engine(*game, *lfb);
    Util::Game::GameManager<TestDemo>::setGame(game);

    engine.run();
    return 0;
}