//
// Created by malte on 20.12.22.
//

#ifndef HHUOS_GRAVITYCOMPONENT_H
#define HHUOS_GRAVITYCOMPONENT_H


#include "Component.h"

namespace Util::Game {
    class GravityComponent : public Component {
    public:
        explicit GravityComponent(double groundY, double mass = 1, double stopFactorX = 0.9, double gravityValue = -1);

    protected:
        void update(double dt) override;

    private:
        Memory::String type = "GravityComponent";

        const double groundY;
        const double mass;
        const double stopFactorX;
        const double gravityValue;
    };
}

#endif //HHUOS_GRAVITYCOMPONENT_H
