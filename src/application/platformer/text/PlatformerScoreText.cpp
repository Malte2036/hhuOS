//
// Created by Malte Sehmer on 06.01.23.
//

#include "PlatformerScoreText.h"

PlatformerScoreText::PlatformerScoreText(const Vector2 &position, int score) : GameText(position,
                                                                                        Util::Memory::String::format("Score: %d",
                                                                                                           score)),
                                                                               score{score} {


}

void PlatformerScoreText::increaseScore() {
    score++;
    setText(Util::Memory::String::format("Score: %d", score));
}