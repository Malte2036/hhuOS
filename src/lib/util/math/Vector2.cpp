//
// Created by malte on 05.12.22.
//

#include "Vector2.h"

Vector2::Vector2() : x{0}, y{0} {}

Vector2::Vector2(double x, double y) : x{x}, y{y} {}

double Vector2::getX() const {
    return x;
}

double Vector2::getY() const {
    return y;
}

Vector2 Vector2::add(Vector2 other) {
    return {x + other.getX(), y + other.getY()};
}
