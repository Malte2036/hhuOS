//
// Created by malte on 08.01.23.
//

#ifndef HHUOS_SCENE_H
#define HHUOS_SCENE_H


#include "lib/util/game/entity/Entity.h"
#include "lib/util/data/Pair.h"
#include "lib/util/game/KeyListener.h"
#include "lib/util/game/MouseListener.h"

namespace Util::Game {
    class Scene {
        friend class Engine;
        friend class Game;

    public:
        Scene() = default;

        /**
         * Copy Constructor.
         */
        Scene(const Scene &other) = delete;

        /**
         * Assignment operator.
         */
        Scene &operator=(const Scene &other) = delete;

        /**
         * Destructor.
         */
        virtual ~Scene();

        Camera *getCamera();

        void addEntity(Entity *entity);

        void removeEntity(Entity *entity);

    protected:
        virtual void init() = 0;

        void setKeyListener(KeyListener &listener);

        void setMouseListener(MouseListener &listener);

        [[nodiscard]] uint32_t getObjectCount() const;

        void applyChanges();

        void draw(Graphics2D &graphics);

        virtual void update(double dt) = 0;

        void addObject(Drawable *drawable);

        void removeObject(Drawable *drawable);

        void updateEntities(double dt);

        void checkCollision();

        virtual void drawInitialBackground(Graphics2D &graphics) = 0;

    private:
        KeyListener *keyListener = nullptr;
        MouseListener *mouseListener = nullptr;

        Camera *camera = new Camera(Vector2());

        Util::Data::ArrayList<Entity *> entities;

        Util::Data::ArrayList<Drawable *> drawables;
        Util::Data::ArrayList<Drawable *> addList;
        Util::Data::ArrayList<Drawable *> removeList;
        Util::Data::ArrayList<Entity *> removeEntityList;

        static Data::Pair<Entity *, Entity *> createEntityPair(Entity *a, Entity *b);
    };
};


#endif //HHUOS_SCENE_H
