//
// Created by Malte Sehmer on 31.01.23.
//

#ifndef HHUOS_PLATFORMERGRASSBLOCKENTITY_H
#define HHUOS_PLATFORMERGRASSBLOCKENTITY_H

#include "lib/util/math/Vector2.h"
#include "PlatformerBlockEntity.h"

class PlatformerGrassBlockEntity : public PlatformerBlockEntity {
public:
    explicit PlatformerGrassBlockEntity(const Vector2 &position, int countX = 1, int countY = 1);
};


#endif //HHUOS_PLATFORMERGRASSBLOCKENTITY_H
