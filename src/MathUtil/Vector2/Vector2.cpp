#pragma once
#include "./Vector2.h"
#include <iostream>
#include <cmath>

using namespace MathUtil;

Vector2::Vector2()
{
}

Vector2::Vector2(Vector2 *other)
{
    this->x = other->x;
    this->y = other->x;
}

Vector2::Vector2(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vector2::~Vector2()
{
}

Vector2 &Vector2::operator=(const Vector2 &other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Vector2 &Vector2::operator-(const Vector2 &other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vector2 &Vector2::operator+(const Vector2 &other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2 &Vector2::operator*(const double &scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector2 &Vector2::operator*(const float &scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector2 &Vector2::operator*(const int &scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector2 &Vector2::operator/(const double &scalar)
{
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}

Vector2 &Vector2::operator/(const float &scalar)
{
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}

Vector2 &Vector2::operator/(const int &scalar)
{
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Vector2 &vec)
{
    return os << "[" << vec.x << ", " << vec.y << "]";
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