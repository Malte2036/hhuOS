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

#include "lib/util/async/Thread.h"
#include "MouseListener.h"
#include "Engine.h"
#include "GameManager.h"
#include "lib/util/graphic/Ansi.h"
#include "lib/util/stream/FileInputStream.h"
#include "lib/util/io/KeyDecoder.h"
#include "lib/util/file/File.h"
#include "lib/util/memory/HeapMemoryManager.h"
#include "RessourceManager.h"

namespace Util::Game
{

    Engine::Engine(Game &game, const Util::Graphic::LinearFrameBuffer &lfb, const uint8_t targetFrameRate) : game(game), graphics(lfb, game), targetFrameRate(targetFrameRate)
    {
        double resX = lfb.getResolutionX();
        double resY = lfb.getResolutionY();
        GameManager::setResolution(
            new Vector2((resX > resY ? resX / resY : 1) * 2, (resY > resX ? resY / resX : 1) * 2));
        GameManager::setTransformation((int)((resX > resY ? resY : resX) / 2));
    }

    //template<typename GameType>
    Engine* Engine::setup(Game &game) {
        auto lfbFile = new Util::File::File("/device/lfb");
        auto lfb = new Util::Graphic::LinearFrameBuffer(*lfbFile);

        //Util::Game::GameManager::setGame<GameType>(game);
        return new Util::Game::Engine(game, *lfb);
    }

    void Engine::runWithScene(Scene *initialScene)
    {
        game.scene = initialScene;
        run();
    }

    void Engine::run()
    {
        const auto delta = 1.0 / targetFrameRate;
        const auto deltaMilliseconds = static_cast<uint32_t>(delta * 1000);

        Graphic::Ansi::prepareGraphicalApplication(true);

        Async::Thread::createThread("Key-Listener", new KeyListenerRunnable(*this));
        Async::Thread::createThread("Mouse-Listener", new MouseListenerRunnable(*this));

        game.init();

        while (game.isRunning())
        {
            statistics.startFrameTime();
            statistics.startUpdateTime();
            double frameTime = statistics.getLastFrameTime() / 1000.0;
            if (frameTime < 0.001)
            {
                frameTime = 0.001;
            }

            if (game.isNewScenePushed())
            {
                game.initScene(graphics);
            }

            auto scene = game.getScene();

            updateLock.acquire();
            scene->update(frameTime);
            scene->updateEntities(frameTime);
            scene->checkCollision();
            scene->applyChanges();
            statistics.stopUpdateTimeTime();
            updateLock.release();

            statistics.startDrawTime();
            scene->draw(graphics);

            drawStatus();
            graphics.show();
            statistics.stopDrawTime();

            const auto drawTime = statistics.getLastDrawTime();
            const auto updateTime = statistics.getLastUpdateTime();
            if (drawTime + updateTime < deltaMilliseconds)
            {
                statistics.startIdleTime();
                Async::Thread::sleep(Time::Timestamp::ofMilliseconds(deltaMilliseconds - (drawTime + updateTime)));
                statistics.stopIdleTime();
            }

            statistics.incFrames();
            statistics.stopFrameTime();
        }

        RessourceManager::deleteAllImages();
        Graphic::Ansi::cleanupGraphicalApplication();
    }

    void Engine::drawStatus()
    {
        statusUpdateTimer += statistics.getLastFrameTime();
        if (statusUpdateTimer > 1000)
        {
            status = statistics.gather();
            statusUpdateTimer = 0;
        }

        auto color = graphics.getColor();
        graphics.setColor(Util::Graphic::Colors::WHITE);
        graphics.drawStringSmall(-1, 1,
                                 status + Memory::String::format(", Objects: %u", game.getScene()->getObjectCount()));
        auto *memoryManager = (Memory::HeapMemoryManager*) 0x1000;
        auto heapUsed = (memoryManager->getTotalMemory() - memoryManager->getFreeMemory());
        auto heapUsedM = heapUsed / 1000 / 1000;
        auto heapUsedK = (heapUsed - heapUsedM * 1000 * 1000) / 1000;
        graphics.drawStringSmall(-1, 0.97, Memory::String::format("Heap used: %u.%03u MB", heapUsedM, heapUsedK));

        graphics.setColor(color);
    }

    Engine::KeyListenerRunnable::KeyListenerRunnable(Engine &engine) : engine(engine) {}

    void Engine::KeyListenerRunnable::run()
    {
        auto keyboardStream = Stream::FileInputStream("/device/keyboard");
        auto keyDecoder = Io::KeyDecoder();
        int16_t scancode = keyboardStream.read();

        while (engine.game.isRunning() && scancode != -1)
        {
            if (keyDecoder.parseScancode(scancode))
            {
                auto key = keyDecoder.getCurrentKey();
                if (engine.game.getScene()->keyListener != nullptr)
                {
                    engine.updateLock.acquire();
                    key.isPressed() ? engine.game.getScene()->keyListener->keyPressed(key) : engine.game.getScene()->keyListener->keyReleased(key);
                    engine.updateLock.release();
                }
            }

            scancode = keyboardStream.read();
        }
    }

    Engine::MouseListenerRunnable::MouseListenerRunnable(Engine &engine) : engine(engine) {}

    void Engine::MouseListenerRunnable::run()
    {
        auto file = Util::File::File("/device/mouse");
        if (!file.exists())
        {
            return;
        }

        uint8_t lastButtons = 0;

        auto stream = Util::Stream::FileInputStream(file);
        while (engine.game.isRunning())
        {
            auto buttons = stream.read();
            auto xMovement = static_cast<int8_t>(stream.read());
            auto yMovement = static_cast<int8_t>(stream.read());

            if (engine.game.getScene()->mouseListener == nullptr)
            {
                continue;
            }

            engine.updateLock.acquire();
            checkKey(MouseListener::LEFT, lastButtons, buttons);
            checkKey(MouseListener::RIGHT, lastButtons, buttons);
            checkKey(MouseListener::MIDDLE, lastButtons, buttons);
            lastButtons = buttons;

            if (xMovement != 0 || yMovement != 0)
            {
                engine.game.getScene()->mouseListener->mouseMoved(xMovement / static_cast<double>(INT8_MAX),
                                                                  -yMovement / static_cast<double>(INT8_MAX));
            }
            engine.updateLock.release();
        }
    }

    void Engine::MouseListenerRunnable::checkKey(MouseListener::Key key, uint8_t lastButtonState,
                                                 uint8_t currentButtonState)
    {
        if (!(lastButtonState & key) && (currentButtonState & key))
        {
            engine.game.getScene()->mouseListener->keyPressed(key);
        }
        else if ((lastButtonState & key) && !(currentButtonState & key))
        {
            engine.game.getScene()->mouseListener->keyReleased(key);
        }
    }

}