//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_GRAVITYENTITY_H
#define HHUOS_GRAVITYENTITY_H

#include "Entity.h"

namespace Util::Game {
    class GravityEntity : public Entity {
    public:
        GravityEntity(const Memory::String tag, const Vector2 position);

    private:
        void performTransformation(double frameTime) override;

        Vector2 calculateNewtonGravity();

    };
}


#endif //HHUOS_GRAVITYENTITY_H
