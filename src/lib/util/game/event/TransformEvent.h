//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_TRANSFORMEVENT_H
#define HHUOS_TRANSFORMEVENT_H

#include "lib/util/memory/String.h"
#include "lib/util/math/Vector2.h"
#include "CancelableEvent.h"


namespace Util::Game {
    class TransformEvent : public CancelableEvent {
    public:
        explicit TransformEvent(Vector2 transformTo);

        Vector2 getTransformTo();

    private:
        Memory::String type = "TransformEvent";

        Vector2 transformTo;
    };
}


#endif //HHUOS_TRANSFORMEVENT_H
