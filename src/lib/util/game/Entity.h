//
// Created by malte on 04.12.22.
//

#include "Drawable.h"
#include "lib/util/math/Vector2.h"
#include "lib/util/game/event/TransformEvent.h"

namespace Util::Game {
    class Entity : public Drawable {
    public:
        Entity(Vector2 position, double size, Graphic::Color color);

        void draw(Graphics2D &graphics) const override;

        void transform(Vector2 vector2);

        virtual void onTransformEvent(TransformEvent *event) = 0;

        Vector2 getPosition();

        void setPosition(Vector2 vector2);

        double getSize();

        void setColor(Graphic::Color newColor);

    private:
        Vector2 position;
        double size;
        Graphic::Color color;
    };

}

