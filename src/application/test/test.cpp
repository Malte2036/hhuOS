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
#include "lib/util/file/image/Image.h"
#include "TestDemo.h"
#include "lib/util/game/Engine.h"
#include "lib/util/game/GameManager.h"
#include "TestDemoScene.h"
#include "lib/util/file/File.h"

bool isRunning = true;

int32_t main(int32_t argc, char *argv[]) {
    Logger::logMessage("Starting test game!");

    auto game = new TestDemo();
    auto engine = Util::Game::Engine::setup(*game);

    Util::Game::GameManager::setGame<TestDemo>(game);

    auto scene = new TestDemoScene();

    engine->runWithScene(scene);
    return 0;
}