//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_RECTANGLECOLLIDER_H
#define HHUOS_RECTANGLECOLLIDER_H

#include "Collider.h"

namespace Util::Game {
    class RectangleCollider : public Collider {
    public:
        explicit RectangleCollider(double height, double width);

        bool isColliding(Collider &other) override;

    private:
        const double height, width;
    };
}


#endif //HHUOS_RECTANGLECOLLIDER_H
