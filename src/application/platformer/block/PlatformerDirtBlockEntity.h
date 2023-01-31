//
// Created by Malte Sehmer on 31.01.23.
//

#ifndef HHUOS_PLATFORMERDIRTBLOCKENTITY_H
#define HHUOS_PLATFORMERDIRTBLOCKENTITY_H


#include "lib/util/math/Vector2.h"
#include "PlatformerBlockEntity.h"

class PlatformerDirtBlockEntity : public PlatformerBlockEntity {
public:
    explicit PlatformerDirtBlockEntity(const Vector2 &position, int countX = 1);
};


#endif //HHUOS_PLATFORMERDIRTBLOCKENTITY_H
