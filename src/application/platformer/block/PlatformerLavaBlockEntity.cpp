//
// Created by Malte Sehmer on 01.02.23.
//

#include "PlatformerLavaBlockEntity.h"

PlatformerLavaBlockEntity::PlatformerLavaBlockEntity(const Vector2 &position, int countX, int countY)
        : PlatformerBlockEntity(
        "LavaBlock", position, "/initrd/game/platformer/ground/lava_middle.bmp", countX, countY) {

}
