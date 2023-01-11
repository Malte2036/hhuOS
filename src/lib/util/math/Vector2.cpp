//
// Created by malte on 05.12.22.
//

#include "Vector2.h"
#include "Math.h"

Vector2::Vector2() : x{0}, y{0} {}

Vector2::Vector2(double x, double y) : x{x}, y{y} {}

double Vector2::getX() const {
    return x;
}

double Vector2::getY() const {
    return y;
}

Vector2 &Vector2::operator*(const double value) const {
    return *new Vector2(x * value, y * value);
}

Vector2 &Vector2::operator/(double value) const {
    return *new Vector2(x / value, y / value);
}

Vector2 &Vector2::operator+(const Vector2 &other) const {
    return *new Vector2(x + other.x, y + other.y);
}

Vector2 &Vector2::operator-(const Vector2 &other) const {
    return *new Vector2(x - other.x, y - other.y);
}

double Vector2::length() const {
    return Util::Math::Math::sqrt(x * x + y * y);
}

Vector2 Vector2::normalize() const {
    if (length() == 0) return *this;
    return *this / length();
}

double Vector2::dotProduct(const Vector2 &other) const {
    return (x * other.x) + (y * other.y);
}

