//
// Created by Malte Sehmer on 31.01.23.
//

#include "PlatformerDirtBlockEntity.h"

PlatformerDirtBlockEntity::PlatformerDirtBlockEntity(const Vector2 &position, int countX, int countY)
        : PlatformerBlockEntity(
        "DirtBlock", position, "/initrd/game/platformer/ground/ground_dirt_middle.bmp", countX, countY) {

}
