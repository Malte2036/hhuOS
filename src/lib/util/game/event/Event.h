//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_EVENT_H
#define HHUOS_EVENT_H

#include "lib/util/memory/String.h"

namespace Util::Game {
    class Event {
    public:
        Memory::String getType();

        bool isCanceled();
        void setCanceled(bool value);

    private:
        Memory::String type;

        bool canceled = false;
    };
}

#endif //HHUOS_EVENT_H
