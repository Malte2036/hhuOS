//
// Created by Malte Sehmer on 05.12.22.
//

#ifndef HHUOS_TRANSLATEEVENT_H
#define HHUOS_TRANSLATEEVENT_H

#include "lib/util/memory/String.h"
#include "lib/util/math/Vector2.h"
#include "CancelableEvent.h"


namespace Util::Game {
    class TranslateEvent : public CancelableEvent {
    public:
        explicit TranslateEvent(const Vector2 &translateTo);

        /**
         * Copy Constructor.
        */
        TranslateEvent(const TranslateEvent &other) = delete;

        /**
         * Assignment operator.
         */
        TranslateEvent &operator=(const TranslateEvent &other) = delete;

        Vector2 getTranslateTo();

    private:
        Memory::String type = "TranslateEvent";

        Vector2 translateTo;
    };
}


#endif //HHUOS_TRANSLATEEVENT_H
