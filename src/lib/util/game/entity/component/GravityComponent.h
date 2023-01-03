//
// Created by malte on 20.12.22.
//

#ifndef HHUOS_GRAVITYCOMPONENT_H
#define HHUOS_GRAVITYCOMPONENT_H


#include "Component.h"

namespace Util::Game {
    class GravityComponent : public Component {
    public:
        GravityComponent(double groundY);
        void update(double dt);
    private:
        Memory::String type = "GravityComponent";

        const double groundY;
    };
}

#endif //HHUOS_GRAVITYCOMPONENT_H
