//
// Created by Malte Sehmer on 05.12.22.
//

#ifndef HHUOS_GAMETEXT_H
#define HHUOS_GAMETEXT_H


#include "lib/util/math/Vector2.h"
#include "lib/util/memory/String.h"
#include "Drawable.h"

namespace Util::Game {
    class GameText : public Drawable {
    public:
        GameText(const Vector2 &position, const Memory::String &text);

        GameText(Vector2 position, const Memory::String &text, Graphic::Color color);

        /**
       * Copy Constructor.
       */
        GameText(const GameText &other) = delete;

        /**
         * Assignment operator.
         */
        GameText &operator=(const GameText &other) = delete;

    protected:
        void setText(const Memory::String &value);

    private:
        void draw(Util::Game::Graphics2D &graphics) const override;

        Vector2 position;
        Memory::String text;
        Graphic::Color color;
    };
}


#endif //HHUOS_GAMETEXT_H
