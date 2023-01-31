//
// Created by Malte Sehmer on 07.12.22.
//

#include "PlatformerBrickBlockEntity.h"
#include "lib/util/game/GameManager.h"

PlatformerBrickBlockEntity::PlatformerBrickBlockEntity(const Vector2 &position, int countX)
        : PlatformerBlockEntity("BrickBlock", position, "/initrd/game/platformer/block/block_brick.bmp", countX) {
}
