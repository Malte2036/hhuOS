//
// Created by Malte Sehmer on 05.12.22.
//

#include "TranslateEvent.h"

namespace Util::Game {
    TranslateEvent::TranslateEvent(const Vector2& translateTo) : translateTo{translateTo} {}

    Vector2 TranslateEvent::getTranslateTo() {
        return translateTo;
    }
}
