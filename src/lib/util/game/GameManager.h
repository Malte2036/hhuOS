//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_GAMEMANAGER_H
#define HHUOS_GAMEMANAGER_H

#include "Game.h"
#include "Engine.h"

namespace Util::Game {

    class GameManager {

    public:
        template<typename GameType>
        static void setGame(GameType *value) {
            game<GameType> = value;
        };

        template<typename GameType>
        static GameType *getGame() {
            return game<GameType>;
        }

        static Vector2 getResolution() {
            return *resolution;
        }

        static double getTransformation() {
            return transformation;
        }

    protected:
        friend Engine;

        static void setResolution(Vector2 *vector2) {
            resolution = vector2;
        }

        static void setTransformation(int value) {
            transformation = value;
        }

    private:
        template<typename GameType>
        inline static GameType *game = nullptr;
        inline static Vector2 *resolution = nullptr;
        inline static int transformation = 0;
    };
}


#endif //HHUOS_GAMEMANAGER_H
