//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_GAMETEXT_H
#define HHUOS_GAMETEXT_H


#include "lib/util/math/Vector2.h"
#include "lib/util/memory/String.h"
#include "Drawable.h"

namespace Util::Game {
    class GameText : public Drawable {
    public:
        GameText(Vector2 position, Memory::String text);
        GameText(Vector2 position, Memory::String text, Graphic::Color color);

        void draw(Util::Game::Graphics2D &graphics) const override;

    private:
        Vector2 position;
        Memory::String text;
        Graphic::Color color;
    };
}


#endif //HHUOS_GAMETEXT_H
