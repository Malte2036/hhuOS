//
// Created by Malte Sehmer on 16.12.22.
//

#include "Sprite.h"

#include "lib/util/file/bmp/BMP.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/game/RessourceManager.h"

namespace Util::Game {
    Sprite::Sprite(const Memory::String &filename, double width, double height) {
        width += 0.0025;
        height += 0.0025;

        key = filename + Memory::String::format("_%d_%d", width, height);
        if (RessourceManager::hasImage(key)) {
            image = RessourceManager::getImage(key);
        } else {
            auto file = File::Image::BMP::fromFile(filename);

            auto transformation = GameManager::getTransformation();
            image = File::Image::Image::scale((int) (width * transformation), (int) (height * transformation),
                                              *file);
            delete file;

            RessourceManager::addImage(key, image);
        }
    }

    File::Image::Image *Sprite::getImage() const {
        return image;
    }

    Sprite::~Sprite() {
        RessourceManager::deleteImage(key);
    }

}