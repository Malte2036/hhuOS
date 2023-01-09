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

#ifndef HHUOS_GAME_H
#define HHUOS_GAME_H

#include "lib/util/data/ArrayList.h"
#include "Graphics2D.h"
#include "Drawable.h"
#include "KeyListener.h"
#include "MouseListener.h"
#include "lib/util/game/entity/Entity.h"
#include "Camera.h"
#include "lib/util/data/Pair.h"
#include "lib/util/game/scene/Scene.h"

namespace Util::Game {

    class Game {
        friend class Engine;

    public:
        Game() = default;

        /**
         * Copy Constructor.
         */
        Game(const Game &other) = delete;

        /**
         * Assignment operator.
         */
        Game &operator=(const Game &other) = delete;

        /**
         * Destructor.
         */
        virtual ~Game();

        /**
         * stop the game
         */
        void stop();


        /**
         * @return the current scene
         */
        Scene *getScene();

        /**
         * start a new scene
         * @param newScene
         */
        void pushScene(Scene *newScene);

    protected:
        [[nodiscard]] bool isRunning() const;

        virtual void onUpdate(double dt) = 0;

        void initScene(Graphics2D &graphics);

        [[nodiscard]] bool isNewScenePushed() const;

    private:
        Scene *scene = nullptr;
        bool newScenePushed = true;

        bool running = true;
    };

}

#endif
