//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_VECTOR2_H
#define HHUOS_VECTOR2_H


class Vector2 {
public:
    Vector2();

    Vector2(double x, double y);

    Vector2(const Vector2 &other) = default;

    Vector2 &operator=(const Vector2 &other) = default;

    virtual ~Vector2() = default;

    Vector2 &operator*(double value) const;

    Vector2 &operator/(double value) const;

    Vector2 &operator+(const Vector2 &other) const;

    Vector2 &operator-(const Vector2 &other) const;

    [[nodiscard]] Vector2 normalize() const;

    [[nodiscard]] double dotProduct(const Vector2 &other) const;

    [[nodiscard]] double length() const;

    [[nodiscard]] double getX() const;

    [[nodiscard]] double getY() const;

private:
    double x;
    double y;
};


#endif //HHUOS_VECTOR2_H
