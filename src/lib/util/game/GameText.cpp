//
// Created by malte on 05.12.22.
//

#include "GameText.h"

namespace Util::Game {
    GameText::GameText(const Vector2& position, const Memory::String& text) : position{position}, text{text},
                                                                color{Graphic::Colors::WHITE} {}

    GameText::GameText(Vector2 position, const Memory::String& text, Graphic::Color color = Graphic::Colors::WHITE) : position{
            position}, text{text}, color{color} {}

    void GameText::draw(Graphics2D &graphics) const {
        graphics.setColor(color);
        graphics.drawString(position.getX(), position.getY(), text);
    }

    void GameText::setText(const Memory::String& value) {
        text = value;
    }
}
