#pragma once
#include <type_traits>
#include <iostream>

namespace MathUtil
{
    class Vector2
    {
    private:
    public:
        constexpr Vector2();
        constexpr Vector2(Vector2 *);
        constexpr Vector2(double x, double y);
        constexpr Vector2(float x, float y);
        constexpr Vector2(int x, int y);
        ~Vector2() = default;
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
        double x = 0;
        double y = 0;
    };
}