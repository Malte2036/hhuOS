//
// Created by Malte Sehmer on 01.01.23.
//

#include "SpriteAnimation.h"
#include "lib/util/game/GameManager.h"

namespace Util::Game {

    SpriteAnimation::SpriteAnimation(const Data::Array<Sprite *> &allSprites, int animationTimeMiliSeconds) :
            animationTimeMiliSeconds{animationTimeMiliSeconds}, sprites{allSprites} {
    }

    Sprite *SpriteAnimation::getNextSprite() {
        frame++;
        if (frame >= sprites.length()) {
            frame = 0;
        }
        return sprites[frame];
    }

    Sprite *SpriteAnimation::getCurrentSprite(double dt) {
        auto targetFrameRate = GameManager::getTargetFrameRate();
        auto totalFrameCount = targetFrameRate * animationTimeMiliSeconds;
        auto frameCountPerSprite = totalFrameCount / sprites.length();

        auto nextFrameAt = frameCountPerSprite * animationFrame;

        return getNextSprite();
    }

    SpriteAnimation::~SpriteAnimation() {
        for (auto *sprite: sprites) {
            delete sprite;
        }
        sprites.clear();
    }
}
