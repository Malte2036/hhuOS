//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_CANCELABLEEVENT_H
#define HHUOS_CANCELABLEEVENT_H

#include "Event.h"

namespace Util::Game {
    class CancelableEvent : public Event {
    public:
        CancelableEvent() = default;

        bool isCanceled();
        void setCanceled(bool value);

    private:
        bool canceled = false;
    };
}


#endif //HHUOS_CANCELABLEEVENT_H