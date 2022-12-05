//
// Created by malte on 04.12.22.
//

#include "Drawable.h"

namespace Util::Game {
    class Entity : public Drawable {
    public:
        Entity(double initialX, double initialY, Graphic::Color initialColor);

        void draw(Graphics2D &graphics) const override;

        void transform(double xTransform, double yTransform);

        double getX();

        double getY();

        void setColor(Graphic::Color newColor);

    private:
        double x, y;
        Graphic::Color color;
    };

}

