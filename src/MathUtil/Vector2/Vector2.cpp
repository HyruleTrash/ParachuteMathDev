#pragma once
#include "./Vector2.h"
#include <iostream>
#include <cmath>
#include "Vector2.h"

using namespace MathUtil;

constexpr Vector2::Vector2()
{
}

constexpr Vector2::Vector2(Vector2 *other)
{
    this->x = other->x;
    this->y = other->y;
}

constexpr Vector2::Vector2(double x, double y)
{
    this->x = x;
    this->y = y;
}

constexpr Vector2::Vector2(float x, float y) : Vector2((double)x, (double)y)
{
}

constexpr Vector2::Vector2(int x, int y) : Vector2((double)x, (double)y)
{
}

constexpr static Vector2 V2_ZERO{0, 0};
constexpr static Vector2 V2_UP{0, -1};
constexpr static Vector2 V2_DOWN{0, 1};
constexpr static Vector2 V2_LEFT{-1, 0};
constexpr static Vector2 V2_RIGHT{1, 0};

std::ostream &operator<<(std::ostream &os, const Vector2 &vec)
{
    return os << "[" << vec.x << ", " << vec.y << "]";
}

Vector2 &Vector2::operator=(const Vector2 &other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2 &other)
{
    Vector2 result{this};
    result.x -= other.x;
    result.y -= other.y;
    return result;
}

Vector2 Vector2::operator+(const Vector2 &other)
{
    Vector2 result{this};
    result.x += other.x;
    result.y += other.y;
    return result;
}

Vector2 Vector2::operator*(const double &scalar)
{
    Vector2 result{this->x * scalar, this->y * scalar};
    return result;
}

Vector2 Vector2::operator*(const float &scalar)
{
    Vector2 result{this};
    return result * (double)scalar;
}

Vector2 Vector2::operator*(const int &scalar)
{
    Vector2 result{this};
    return result * (double)scalar;
}

const Vector2 Vector2::operator*(const double &scalar) const
{
    Vector2 result{this->x * scalar, this->y * scalar};
    return result;
}

const Vector2 Vector2::operator*(const float &scalar) const
{
    Vector2 result{this->x * scalar, this->y * scalar};
    return result;
}

const Vector2 Vector2::operator*(const int &scalar) const
{
    Vector2 result{this->x * scalar, this->y * scalar};
    return result;
}

Vector2 Vector2::operator/(const double &scalar)
{
    Vector2 result{this->x / scalar, this->y / scalar};
    return result;
}

Vector2 Vector2::operator/(const float &scalar)
{
    Vector2 result{this};
    return result / (double)scalar;
}

Vector2 Vector2::operator/(const int &scalar)
{
    Vector2 result{this};
    return result / (double)scalar;
}

bool Vector2::operator==(const Vector2 &other)
{
    if (this->x == other.x && this->y == other.y)
        return true;
    return false;
}

const bool Vector2::operator==(const Vector2 &other) const
{
    if (this->x == other.x && this->y == other.y)
        return true;
    return false;
}

bool Vector2::operator!=(const Vector2 &other)
{
    if (this->x != other.x || this->y != other.y)
        return true;
    return false;
}

const bool Vector2::operator!=(const Vector2 &other) const
{
    if (this->x != other.x || this->y != other.y)
        return true;
    return false;
}

Vector2 &Vector2::operator+=(const Vector2 &other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vector2 &Vector2::operator*=(const Vector2 &other)
{
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

Vector2 &Vector2::operator/=(const Vector2 &other)
{
    if (other == V2_ZERO)
    {
        this->x = 0;
        this->y = 0;
        return *this;
    }
    this->x /= other.x;
    this->y /= other.y;
    return *this;
}

Vector2 &Vector2::operator*=(const double &scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector2 &Vector2::operator*=(const float &scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector2 &Vector2::operator*=(const int &scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector2 &Vector2::operator/=(const double &scalar)
{
    if (scalar == 0)
    {
        this->x = 0;
        this->y = 0;
        return *this;
    }
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}

Vector2 &Vector2::operator/=(const float &scalar)
{
    if (scalar == 0)
    {
        this->x = 0;
        this->y = 0;
        return *this;
    }
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}

Vector2 &Vector2::operator/=(const int &scalar)
{
    if (scalar == 0)
    {
        this->x = 0;
        this->y = 0;
        return *this;
    }
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}

Vector2 Vector2::operator-()
{
    Vector2 result{-this->x, -this->y};
    return result;
}

const Vector2 Vector2::operator-() const
{
    Vector2 result{-this->x, -this->y};
    return result;
}

double Vector2::GetMagnitude()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

double Vector2::GetCubicVolume()
{
    return (this->x * this->y);
}

Vector2 Vector2::Normalize()
{
    double mag = this->GetMagnitude();
    Vector2 result = Vector2{this} / mag;
    return result;
}