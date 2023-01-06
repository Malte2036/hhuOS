//
// Created by malte on 06.01.23.
//

#include "MarioScoreText.h"

MarioScoreText::MarioScoreText(const Vector2 &position, int score) : GameText(position,
                                                                              Util::Memory::String::format("Score: %d",
                                                                                                           score)),
                                                                     score{score} {


}

void MarioScoreText::increaseScore() {
    score++;
    setText(Util::Memory::String::format("Score: %d", score));
}