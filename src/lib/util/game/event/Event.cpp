//
// Created by malte on 05.12.22.
//

#include "Event.h"

Util::Memory::String Util::Game::Event::getType() {
    return type;
}

bool Util::Game::Event::isCanceled() {
    return canceled;
}

void Util::Game::Event::setCanceled(bool value) {
    canceled = value;
}

