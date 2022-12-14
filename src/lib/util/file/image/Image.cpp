//
// Created by malte on 07.12.22.
//

#include "Image.h"

namespace Util::File::Image {

    Image::~Image() {
        delete pixelBuf;
    }

    Image::Image(int width, int height, Graphic::Color *pixelBuff) : pixelBuf{pixelBuff}, width{width}, height{height} {

    }

    Graphic::Color *Image::getPixelBuffer() const {
        return pixelBuf;
    }

    int Image::getWidth() const {
        return width;
    }

    int Image::getHeight() const {
        return height;
    }
}
