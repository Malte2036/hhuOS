//
// Created by Malte Sehmer on 06.01.23.
//
#include "PlatformerProjectileText.h"

PlatformerProjectileText::PlatformerProjectileText(const Vector2 &position) : GameText(position, "") {


}

void PlatformerProjectileText::setCount(int count) {
    setText(Util::Memory::String::format("Projectile: %d", count));
}