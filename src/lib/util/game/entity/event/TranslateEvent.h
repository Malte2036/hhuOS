//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_TRANSLATEEVENT_H
#define HHUOS_TRANSLATEEVENT_H

#include "lib/util/memory/String.h"
#include "lib/util/math/Vector2.h"
#include "CancelableEvent.h"


namespace Util::Game {
    class TranslateEvent : public CancelableEvent {
    public:
        explicit TranslateEvent(Vector2 translateTo);

        Vector2 getTranslateTo();

    private:
        Memory::String type = "TranslateEvent";

        Vector2 translateTo;
    };
}


#endif //HHUOS_TRANSLATEEVENT_H
