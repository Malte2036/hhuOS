//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_GAMEMANAGER_H
#define HHUOS_GAMEMANAGER_H

#include "Game.h"
#include "Engine.h"

namespace Util::Game {

    template<typename GameType>
    class GameManager {

    public:
        static void setGame(GameType *value) {
            game = value;
        };

        static GameType *getGame() {
            return game;
        }

    private:
        inline static GameType *game = nullptr;
    };

}


#endif //HHUOS_GAMEMANAGER_H
