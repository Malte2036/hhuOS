//
// Created by malte on 16.12.22.
//

#include "Sprite.h"

#include "lib/util/file/bmp/BMP.h"

namespace Util::Game {

    Sprite::Sprite(const Memory::String& filename) : image{File::Image::BMP::fromFile(filename)} {

    }

    File::Image::Image *Sprite::getImage() const {
        return image;
    }

}