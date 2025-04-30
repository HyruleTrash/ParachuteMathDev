#pragma once
#include <iostream>

namespace MathUtil
{
    class Vector2
    {
    public:
        double x = 0;
        double y = 0;

        static const Vector2 ZERO;
        static const Vector2 UP;
        static const Vector2 DOWN;
        static const Vector2 LEFT;
        static const Vector2 RIGHT;
        
    public:
        constexpr Vector2() : x(0.0), y(0.0) {}
        constexpr Vector2(const Vector2 *other) : x(other->x), y(other->y) {}
        constexpr Vector2(double x, double y) : x(x), y(y) {}
        constexpr Vector2(float x, float y) : Vector2((double)x, (double)y) {}
        constexpr Vector2(int x, int y) : Vector2((double)x, (double)y) {}

        friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);
        Vector2 &operator=(const Vector2 &other);
        Vector2 operator+(const Vector2 &other);
        Vector2 operator-(const Vector2 &other);
        Vector2 operator*(const double &scalar);
        Vector2 operator*(const float &scalar);
        Vector2 operator*(const int &scalar);
        const Vector2 operator*(const double &scalar) const;
        const Vector2 operator*(const float &scalar) const;
        const Vector2 operator*(const int &scalar) const;
        Vector2 operator/(const double &scalar);
        Vector2 operator/(const float &scalar);
        Vector2 operator/(const int &scalar);
        bool operator==(const Vector2 &other);
        const bool operator==(const Vector2 &other) const;
        bool operator!=(const Vector2 &other);
        const bool operator!=(const Vector2 &other) const;
        Vector2 &operator+=(const Vector2 &other);
        Vector2 &operator-=(const Vector2 &other);
        Vector2 &operator*=(const Vector2 &other);
        Vector2 &operator/=(const Vector2 &other);
        Vector2 &operator*=(const double &scalar);
        Vector2 &operator*=(const float &scalar);
        Vector2 &operator*=(const int &scalar);
        Vector2 &operator/=(const double &scalar);
        Vector2 &operator/=(const float &scalar);
        Vector2 &operator/=(const int &scalar);
        Vector2 operator-();
        const Vector2 operator-() const;
        double GetMagnitude();
        double GetCubicVolume();
        Vector2 Normalize();
    };
}