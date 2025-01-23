#pragma once
#include "./Vector2.h"
#include <iostream>
#include <cmath>

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
    Vector2 result{this};
    result.x *= scalar;
    result.y *= scalar;
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

Vector2 Vector2::operator/(const double &scalar)
{
    Vector2 result{this};
    result.x /= scalar;
    result.y /= scalar;
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
    this->x /= other.x;
    this->y /= other.y;
    return *this;
}

double Vector2::GetMagnitude()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

Vector2 Vector2::Normalize()
{
    double mag = this->GetMagnitude();
    Vector2 result = Vector2{this} / mag;
    return result;
}