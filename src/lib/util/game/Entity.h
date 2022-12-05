//
// Created by malte on 04.12.22.
//

#include "Drawable.h"
#include "lib/util/math/Vector2.h"
#include "lib/util/game/event/TransformEvent.h"
#include "lib/util/game/collider/Collider.h"
#include "lib/util/game/collider/RectangleCollider.h"

namespace Util::Game {
    class Entity : public Drawable {
    public:
        Entity(const Vector2 &position, double size);

        void transform(const Vector2 &vector2);

        virtual void onTransformEvent(TransformEvent *event) = 0;

        [[nodiscard]] Vector2 getPosition() const;

        void setPosition(const Vector2 &vector2);

        [[nodiscard]] double getSize() const;

        virtual Util::Game::RectangleCollider getCollider() const = 0;

    private:
        Vector2 position;
        double size;
    };

}

