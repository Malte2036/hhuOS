//
// Created by malte on 04.12.22.
//

#include "Drawable.h"

namespace Util::Game {
    class Sprite : public Drawable {
    public:
        Sprite(double initialX, double initialY, Graphic::Color initialColor);

        void draw(Graphics2D &graphics) const override;

    private:
        double x, y;
        Graphic::Color color;
    };

}

