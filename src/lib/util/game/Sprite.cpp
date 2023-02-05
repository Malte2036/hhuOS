//
// Created by Malte Sehmer on 16.12.22.
//

#include "Sprite.h"

#include "lib/util/file/bmp/BMP.h"
#include "lib/util/game/GameManager.h"

namespace Util::Game {
    Sprite::Sprite(const Memory::String &filename, double width, double height) {
        width += 0.0025;
        height += 0.0025;

        auto file = File::Image::BMP::fromFile(filename);

        auto transformation = GameManager::getTransformation();
        image = File::Image::Image::scale((int) (width * transformation), (int) (height * transformation),
                                          *file);
        delete file;
    }

    File::Image::Image *Sprite::getImage() const {
        return image;
    }

    Sprite::~Sprite() {
        delete image;
    }

}