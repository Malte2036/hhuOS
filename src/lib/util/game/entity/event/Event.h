//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_EVENT_H
#define HHUOS_EVENT_H

#include "lib/util/memory/String.h"

namespace Util::Game {
    class Event {
    public:
        Event() = default;

        /**
        * Copy Constructor.
        */
        Event(const Event &other) = delete;

        /**
         * Assignment operator.
         */
        Event &operator=(const Event &other) = delete;

        Memory::String getType();
        
    private:
        Memory::String type;
    };
}

#endif //HHUOS_EVENT_H
