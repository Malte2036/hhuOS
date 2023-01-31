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

#ifndef HHUOS_GRAPHICS2D_H
#define HHUOS_GRAPHICS2D_H

#include <cstdint>

#include "lib/util/graphic/BufferedLinearFrameBuffer.h"
#include "lib/util/graphic/LineDrawer.h"
#include "lib/util/graphic/StringDrawer.h"
#include "lib/util/graphic/Colors.h"
#include "lib/util/math/Vector2.h"
#include "lib/util/file/image/Image.h"
#include "Camera.h"
#include "lib/util/data/Array.h"
#include "lib/util/memory/String.h"


namespace Util::Game {

    class Game;

    class Graphics2D {

    public:
        /**
         * Constructor.
         */
        explicit Graphics2D(const Util::Graphic::LinearFrameBuffer &lfb, Game &game);

        /**
         * Copy Constructor.
         */
        Graphics2D(const Graphics2D &other) = delete;

        /**
         * Assignment operator.
         */
        Graphics2D &operator=(const Graphics2D &other) = delete;

        /**
         * Destructor.
         */
        ~Graphics2D() = default;

        void drawLine(const Vector2 &from, const Vector2 &to) const;

        void drawPolygon(const Data::Array<Vector2> &vertices) const;

        void drawSquare(const Vector2 &position, double size) const;

        void drawRectangle(const Vector2 &position, double height, double width) const;

        void drawString(double x, double y, const char *string) const;

        void drawString(double x, double y, const Util::Memory::String &string) const;

        void drawStringSmall(double x, double y, const char *string) const;

        void drawStringSmall(double x, double y, const Util::Memory::String &string) const;

        void drawImage(const Vector2 &position, const Util::File::Image::Image &image, bool flipX = false) const;

        void show() const;

        void setColor(const Graphic::Color &color);

        [[nodiscard]] Graphic::Color getColor() const;

        void setBackgroundColor(const Graphic::Color &backgroundColor);

        void saveAsBackground();


    private:

        void drawString(const Graphic::Font &font, double x, double y, const char *string) const;

        const Graphic::BufferedLinearFrameBuffer lfb;
        Memory::Address<uint32_t> *backgroundBuffer = nullptr;
        Game &game;

        const Graphic::PixelDrawer pixelDrawer;
        const Graphic::LineDrawer lineDrawer;
        const Graphic::StringDrawer stringDrawer;

        const uint16_t transformation;
        const uint16_t offsetX;
        const uint16_t offsetY;

        Graphic::Color color = Graphic::Colors::WHITE;
        Graphic::Color backgroundColor = Graphic::Colors::BLACK;
    };

}

#endif
