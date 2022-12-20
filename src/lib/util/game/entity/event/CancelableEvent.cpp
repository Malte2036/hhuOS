//
// Created by malte on 05.12.22.
//

#include "CancelableEvent.h"

namespace Util::Game {
    bool CancelableEvent::isCanceled() {
        return canceled;
    }

    void CancelableEvent::setCanceled(bool value) {
        canceled = value;
    }
}
