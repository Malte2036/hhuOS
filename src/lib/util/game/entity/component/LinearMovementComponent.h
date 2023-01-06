//
// Created by malte on 20.12.22.
//

#ifndef HHUOS_LINEARMOVEMENTCOMPONENT_H
#define HHUOS_LINEARMOVEMENTCOMPONENT_H

#include "Component.h"

namespace Util::Game {
    class LinearMovementComponent : public Component{
    protected:
        void update(double dt) override;
    private:
        Memory::String type = "LinearMovementComponent";
    };
}


#endif //HHUOS_LINEARMOVEMENTCOMPONENT_H
