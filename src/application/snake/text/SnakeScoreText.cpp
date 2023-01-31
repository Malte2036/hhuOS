//
// Created by Malte Sehmer on 06.12.22.
//

#include "SnakeScoreText.h"

SnakeScoreText::SnakeScoreText(Vector2 position, int score) :
        Util::Game::GameText(position, "Snake game started", Util::Graphic::Colors::YELLOW) {
    setScore(score);
}

void SnakeScoreText::setScore(int value) {
    setText(Util::Memory::String::format("Score: %u", value));
}
