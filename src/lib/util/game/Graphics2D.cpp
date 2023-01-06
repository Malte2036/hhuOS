/*
 * Copyright (C) 2018-2022 Heinrich-Heine-Universitaet Duesseldorf,
 * Institute of Computer Science, Department Operating Systems
 * Burak Akguel, Christian Gesse, Fabian Ruhland, Filip Krakowski, Michael Schoettner
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include "lib/util/graphic/Fonts.h"
#include "Graphics2D.h"
#include "lib/util/file/image/Image.h"

namespace Util::Game {

    Graphics2D::Graphics2D(const Graphic::LinearFrameBuffer &lfb, Camera *camera) :
            lfb(lfb), camera{camera}, pixelDrawer(Graphics2D::lfb), lineDrawer(pixelDrawer),
            stringDrawer(pixelDrawer),
            transformation(
                    (lfb.getResolutionX() > lfb.getResolutionY() ? lfb.getResolutionY() : lfb.getResolutionX()) / 2),
            offsetX(transformation +
                    (lfb.getResolutionX() > lfb.getResolutionY() ? (lfb.getResolutionX() - lfb.getResolutionY()) / 2
                                                                 : 0)),
            offsetY(transformation +
                    (lfb.getResolutionY() > lfb.getResolutionX() ? (lfb.getResolutionY() - lfb.getResolutionX()) / 2
                                                                 : 0)) {}

    void Graphics2D::drawLine(double x1, double y1, double x2, double y2) const {
        lineDrawer.drawLine(static_cast<int32_t>((x1 - camera->getPosition().getX()) * transformation + offsetX),
                            static_cast<int32_t>((-y1 + camera->getPosition().getY()) * transformation + offsetY),
                            static_cast<int32_t>((x2 - camera->getPosition().getX()) * transformation + offsetX),
                            static_cast<int32_t>((-y2 + camera->getPosition().getY()) * transformation + offsetY),
                            color);
    }

    void Graphics2D::drawPolygon(const Data::Array<double> &x, const Data::Array<double> &y) const {
        for (uint32_t i = 0; i < x.length() - 1; i++) {
            drawLine(x[i], y[i], x[i + 1], y[i + 1]);
        }

        drawLine(x[x.length() - 1], y[y.length() - 1], x[0], y[0]);
    }

    void Graphics2D::drawSquare(const Vector2 &position, double size) const {
        drawRectangle(position, size, size);
    }

    void Graphics2D::drawRectangle(const Vector2 &position, double height, double width) const {
        double x = position.getX();
        double y = position.getY();
        drawLine(x, y, x + width, y);
        drawLine(x, y + height, x + width, y + height);
        drawLine(x, y, x, y + height);
        drawLine(x + width, y, x + width, y + height);
    }

    void Graphics2D::drawImage(const Vector2 &position, const Util::File::Image::Image &image, bool flipX) const {
        auto width = image.getWidth();
        auto pixelBuf = image.getPixelBuffer();

        auto xFlipOffset = flipX ? width : 0;

        int32_t xPixelOffset = (position.getX() - camera->getPosition().getX()) * transformation + offsetX;
        int32_t yPixelOffset = (-position.getY() + camera->getPosition().getY()) * transformation + offsetY;
        for (int32_t i = 0; i < image.getHeight(); i++) {
            for (int32_t j = 0; j < width; j++) {
                pixelDrawer.drawPixel(xPixelOffset + xFlipOffset + (flipX ? -1 : 1) * j, yPixelOffset - i,
                                      pixelBuf[i * width + j]);
            }
        }
    }

    void Graphics2D::drawString(const Graphic::Font &font, double x, double y, const char *string) const {
        stringDrawer.drawString(font, static_cast<int32_t>(x * transformation + offsetX),
                                static_cast<int32_t>(-y * transformation + offsetY), string, color,
                                Util::Graphic::Colors::INVISIBLE);
    }

    void Graphics2D::drawString(double x, double y, const char *string) const {
        drawString(Graphic::Fonts::TERMINAL_FONT, x, y, string);
    }

    void Graphics2D::drawString(double x, double y, const Util::Memory::String &string) const {
        drawString(x, y, static_cast<const char *>(string));
    }

    void Graphics2D::drawStringSmall(double x, double y, const char *string) const {
        drawString(Graphic::Fonts::TERMINAL_FONT_SMALL, x, y, string);
    }

    void Graphics2D::drawStringSmall(double x, double y, const Util::Memory::String &string) const {
        drawStringSmall(x, y, static_cast<const char *>(string));
    }

    void Graphics2D::show() const {
        lfb.flush();
        if (backgroundBuffer == nullptr) {
            lfb.clear();
        } else {
            lfb.clear(*backgroundBuffer);
        }
    }

    void Graphics2D::setColor(const Graphic::Color &color) {
        Graphics2D::color = color;
    }

    Graphic::Color Graphics2D::getColor() const {
        return color;
    }

    void Graphics2D::setBackgroundColor(const Graphic::Color &backgroundColor) {
        Graphics2D::backgroundColor = backgroundColor;
        lfb.clear(backgroundColor);
    }

    void Graphics2D::saveAsBackground() {
        auto size = lfb.getPitch() * lfb.getResolutionY();
        if (backgroundBuffer == nullptr) {
            uint32_t newBackgroundBuffer[size];
            backgroundBuffer = new Memory::Address<uint32_t>(newBackgroundBuffer);
        }

        backgroundBuffer->copyRange(lfb.getBuffer(), size);
    }

}