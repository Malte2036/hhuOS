//
// Created by malte on 07.12.22.
//

#include "Image.h"
#include "lib/util/log/Logger.h"

namespace Util::File::Image {
    void Image::draw(Util::Graphic::PixelDrawer drawer, uint16_t x, uint16_t y) const {
        for (uint16_t i = 0; i < height; i++) {
            for (uint16_t j = 0; j < width; j++) {
                auto color = Graphic::Colors::HHU_BLUE;//pixelBuf[i * width + j];
                drawer.drawPixel(x + j, y - i, color);
                /*if (color == Graphic::Colors::BLACK) {
                    Logger::logMessage("Color is black");
                }else{
                    Logger::logMessage("Color is not black");
                }*/
            }
        }
    }
}
