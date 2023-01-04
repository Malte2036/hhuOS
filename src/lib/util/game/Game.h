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

        void stop();

        Camera* getCamera();

        void addEntity(Entity *entity);

        void removeEntity(Entity *entity);

    protected:
        [[nodiscard]] bool isRunning() const;

        [[nodiscard]] uint32_t getObjectCount() const;

        void applyChanges();

        void draw(Graphics2D &graphics);

        virtual void update(double delta) = 0;

        void addObject(Drawable *drawable);

        void removeObject(Drawable *drawable);

        void setKeyListener(KeyListener &listener);

        void setMouseListener(MouseListener &listener);

        void checkCollision();

        void updateEntities(double frameTime);

    private:

        KeyListener *keyListener = nullptr;
        MouseListener *mouseListener = nullptr;

        Camera *camera = new Camera(Vector2());

        Util::Data::ArrayList<Entity *> entities;

        Util::Data::ArrayList<Drawable *> drawables;
        Util::Data::ArrayList<Drawable *> addList;
        Util::Data::ArrayList<Drawable *> removeList;
        Util::Data::ArrayList<Entity *> removeEntityList;
        bool running = true;

        Util::Data::Pair<Entity *, Entity *> createEntityPair(Entity *a, Entity *b);
    };

}

#endif
