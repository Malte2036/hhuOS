#include "DemoPolygonFactory.h"
#include "lib/util/math/Vector2.h"

const Util::Data::Array<Vector2> DemoPolygonFactory::shape1 = {
        {0,   0},
        {0.5, 1},
        {1,   0}
};
const Util::Data::Array<Vector2> DemoPolygonFactory::shape2 = {
        {0,  1},
        {1,  0},
        {0,  -1},
        {-1, 0}
};
const Util::Data::Array<Vector2> DemoPolygonFactory::shape3 = {
        {0,     1},
        {1,     0.25},
        {0.75,  -1},
        {-0.75, -1},
        {-1,    0.25}
};
const Util::Data::Array<Vector2> DemoPolygonFactory::shape4 = {
        {-0.5, 1},
        {0.5,  1},
        {1,    0},
        {0.5,  -1},
        {-0.5, -1},
        {-1,   0}
};
const Util::Data::Array<Vector2> DemoPolygonFactory::shape5 = {
        {0,     1},
        {0.75,  0.75},
        {1,     -0.25},
        {0.5,   -1},
        {-0.5,  -1},
        {-1,    -0.25},
        {-0.75, 0.75}
};

const Util::Data::Array<const Util::Data::Array<Vector2> *> DemoPolygonFactory::shapes = Util::Data::Array<const Util::Data::Array<Vector2> *>(
        {
                &shape1, &shape2, &shape3, &shape4, &shape5
        });

DemoPolygon *DemoPolygonFactory::createPolygon() {
    const auto shape = static_cast<uint32_t>(random.nextRandomNumber() * shapes.length());
    const auto scaleFactor = random.nextRandomNumber() * 0.5 + 0.1;
    const auto rotationSpeed = random.nextRandomNumber() * 2 - 1.0;
    const auto scaleSpeed = random.nextRandomNumber();
    const auto translation = Vector2(random.nextRandomNumber() * 2 - 1.0, random.nextRandomNumber() * 2 - 1.0);
    const auto color = Util::Graphic::Color(static_cast<uint8_t>(random.nextRandomNumber() * 256),
                                            static_cast<uint8_t>(random.nextRandomNumber() * 256),
                                            static_cast<uint8_t>(random.nextRandomNumber() * 256));

    auto *polygon = new DemoPolygon(*shapes[shape], color, rotationSpeed, scaleSpeed);
    polygon->scale(scaleFactor);
    polygon->translate(translation);
    return polygon;
}