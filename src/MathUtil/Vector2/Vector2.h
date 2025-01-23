#pragma once
#include <type_traits>
#include <iostream>

namespace MathUtil
{
    class Vector2
    {
    private:
    public:
        Vector2();
        Vector2(Vector2 *);
        Vector2(double x, double y);
        ~Vector2();
        Vector2 &operator=(const Vector2 &other);
        Vector2 operator+(const Vector2 &other);
        Vector2 operator-(const Vector2 &other);
        Vector2 operator*(const double &scalar);
        Vector2 operator*(const float &scalar);
        Vector2 operator*(const int &scalar);
        Vector2 operator/(const double &scalar);
        Vector2 operator/(const float &scalar);
        Vector2 operator/(const int &scalar);
        double GetMagnitude();
        Vector2 Normalize();
        double x = 0;
        double y = 0;
    };
}