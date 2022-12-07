//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_GRAVITYENTITY_H
#define HHUOS_GRAVITYENTITY_H

#include "Entity.h"

namespace Util::Game {
    class GravityEntity : public Entity {
    public:
        GravityEntity(const Memory::String& tag, const Vector2& position, double mass);

    private:
        void performTransformation(double frameTime) override;

        const double mass;

    };
}


#endif //HHUOS_GRAVITYENTITY_H
