//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_GAMEMANAGER_H
#define HHUOS_GAMEMANAGER_H

#include "Game.h"
#include "Engine.h"
#include "Sprite.h"

namespace Util::Game {

    class GameManager {

    public:

        /**
         * set the current game, to access it later
         * @tparam GameType
         * @param value
         */
        template<typename GameType>
        static void setGame(GameType *value) {
            game < GameType > = value;
        }

        /**
         * get the current game
         * @tparam GameType
         * @return
         */
        template<typename GameType>
        static GameType *getGame() {
            return game<GameType>;
        }

        /**
         * get the current screen resolution
         * @return Vector with x and y between 0 and 2
         */
        static Vector2 getResolution();

        static void playSound(const Memory::String &soundFileName);

    protected:
        friend Engine;
        friend Sprite;

        static void setResolution(Vector2 *vector2);

        static void setTransformation(int value);

        static double getTransformation();

    private:
        template<typename GameType>
        inline static GameType *game = nullptr;
        inline static Vector2 *resolution = nullptr;
        inline static int transformation = 0;
    };

    class SoundRunnable : public Async::Runnable {
    public:
        explicit SoundRunnable(const Memory::String &soundFileName);

        ~SoundRunnable() override = default;

        void run() override;

    private:
        const Memory::String soundFileName;
    };
}


#endif //HHUOS_GAMEMANAGER_H
