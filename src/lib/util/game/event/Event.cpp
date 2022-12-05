//
// Created by malte on 05.12.22.
//

#include "Event.h"

namespace Util::Game {
    Util::Memory::String Util::Game::Event::getType() {
        return type;
    }

    bool Event::isCanceled() {
        return canceled;
    }

    void Event::setCanceled(bool value) {
        canceled = value;
    }
}

