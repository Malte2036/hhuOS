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
#include "lib/util/async/Thread.h"
#include "lib/util/graphic/Terminal.h"
#include "MouseListener.h"
#include "Engine.h"

namespace Util::Game {

Engine::Engine(Game &game, const Util::Graphic::LinearFrameBuffer &lfb, const uint8_t targetFrameRate) :
        game(game), graphics(lfb), targetFrameRate(targetFrameRate) {}

void Engine::run() {
    const auto delta = 1.0 / targetFrameRate;
    const auto deltaMilliseconds = static_cast<uint32_t>(delta * 1000);

    Graphic::Ansi::prepareGraphicalApplication();

    Async::Thread::createThread("Key-Listener", new KeyListenerRunnable(*this));
    Async::Thread::createThread("Mouse-Listener", new MouseListenerRunnable(*this));

    while (game.isRunning()) {
        statistics.startFrameTime();
        statistics.startUpdateTime();
        double frameTime = statistics.getLastFrameTime() / 1000.0;
        if (frameTime < 0.001) {
            frameTime = 0.001;
        }

        updateLock.acquire();
        game.update(frameTime);
        game.updateEntities(frameTime);
        game.checkCollision();
        game.applyChanges();
        statistics.stopUpdateTimeTime();
        updateLock.release();

        statistics.startDrawTime();
        game.draw(graphics);

        drawStatus();
        graphics.show();
        statistics.stopDrawTime();

        const auto drawTime = statistics.getLastDrawTime();
        const auto updateTime = statistics.getLastUpdateTime();
        if (drawTime + updateTime < deltaMilliseconds) {
            statistics.startIdleTime();
            Async::Thread::sleep(Time::Timestamp::ofMilliseconds(deltaMilliseconds - (drawTime + updateTime)));
            statistics.stopIdleTime();
        }

        statistics.incFrames();
        statistics.stopFrameTime();
    }

    Graphic::Ansi::cleanupGraphicalApplication();
}

void Engine::drawStatus() {
    statusUpdateTimer += statistics.getLastFrameTime();
    if (statusUpdateTimer > 1000) {
        status = statistics.gather();
        statusUpdateTimer = 0;
    }

    auto color = graphics.getColor();
    graphics.setColor(Util::Graphic::Colors::WHITE);
    graphics.drawStringSmall(-1, 1, status + Memory::String::format(", Objects: %u", game.getObjectCount()));
    graphics.setColor(color);
}

Engine::KeyListenerRunnable::KeyListenerRunnable(Engine &engine) : engine(engine) {}

void Engine::KeyListenerRunnable::run() {
    while (engine.game.isRunning()) {
        char c = System::in.read();
        if (engine.game.keyListener != nullptr) {
            engine.updateLock.acquire();
            engine.game.keyListener->keyPressed(c);
            engine.updateLock.release();
        }
    }
}

Engine::MouseListenerRunnable::MouseListenerRunnable(Engine &engine) : engine(engine) {}

void Engine::MouseListenerRunnable::run() {
    auto file = Util::File::File("/device/mouse");
    if (!file.exists()) {
        return;
    }

    uint8_t lastButtons = 0;

    auto stream = Util::Stream::FileInputStream(file);
    while (engine.game.isRunning()) {
        auto buttons = stream.read();
        auto xMovement = static_cast<int8_t>(stream.read());
        auto yMovement = static_cast<int8_t>(stream.read());

        if (engine.game.mouseListener == nullptr) {
            continue;
        }

        engine.updateLock.acquire();
        checkKey(MouseListener::LEFT, lastButtons, buttons);
        checkKey(MouseListener::RIGHT, lastButtons, buttons);
        checkKey(MouseListener::MIDDLE, lastButtons, buttons);
        lastButtons = buttons;

        if (xMovement != 0 || yMovement != 0) {
            engine.game.mouseListener->mouseMoved(xMovement / static_cast<double>(INT8_MAX), -yMovement / static_cast<double>(INT8_MAX));
        }
        engine.updateLock.release();
    }
}

void Engine::MouseListenerRunnable::checkKey(MouseListener::Key key, uint8_t lastButtonState, uint8_t currentButtonState) {
    if (!(lastButtonState & key) && (currentButtonState & key)) {
        engine.game.mouseListener->keyPressed(key);
    } else if ((lastButtonState & key) && !(currentButtonState & key)) {
        engine.game.mouseListener->keyReleased(key);
    }
}

}