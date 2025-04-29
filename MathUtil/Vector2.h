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
        
    public:
        double x = 0;
        double y = 0;
    };

    constexpr static Vector2 V2_ZERO{0, 0};
    constexpr static Vector2 V2_UP{0, -1};
    constexpr static Vector2 V2_DOWN{0, 1};
    constexpr static Vector2 V2_LEFT{-1, 0};
    constexpr static Vector2 V2_RIGHT{1, 0};
}