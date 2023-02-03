//
// Created by Malte Sehmer on 07.12.22.
//

#include "Image.h"
#include "lib/util/math/Math.h"

namespace Util::File::Image {

    Image::Image(int width, int height, Graphic::Color *pixelBuff) : pixelBuf{pixelBuff}, width{width}, height{height} {

    }

    Image::~Image() {
        delete pixelBuf;
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

    Image *Image::scale(int newWidth, int newHeight, const Image& other) {
        auto *newPixelBuf = new Graphic::Color[newWidth * newHeight];

        double factorX = (double) newWidth / other.width;
        double factorY = (double) newHeight / other.height;

        for (int y = 0; y < newHeight; y++) {
            for (int x = 0; x < newWidth; x++) {
                int oldX = (int) (x / factorX);
                int oldY = (int) (y / factorY);
                newPixelBuf[newWidth * y + x] = other.pixelBuf[other.width * oldY + oldX];
            }

        }
        return new Image(newWidth, newHeight, newPixelBuf);
    }
}
