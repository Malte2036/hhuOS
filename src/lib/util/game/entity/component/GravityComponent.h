//
// Created by Malte Sehmer on 20.12.22.
//

#ifndef HHUOS_GRAVITYCOMPONENT_H
#define HHUOS_GRAVITYCOMPONENT_H


#include "Component.h"

namespace Util::Game {
    class GravityComponent : public Component {
    public:
        /**
         *
         * @param groundY the y coordinate of the ground
         * @param mass
         * @param stopFactorX movement stop factor
         * @param gravityValue
         */
        explicit GravityComponent(double groundY, double mass = 2, double stopFactorX = 0.15, double gravityValue = -1.25);

        /**
         * Copy Constructor.
        */
        GravityComponent(const GravityComponent &other) = delete;

        /**
         * Assignment operator.
         */
        GravityComponent &operator=(const GravityComponent &other) = delete;

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
