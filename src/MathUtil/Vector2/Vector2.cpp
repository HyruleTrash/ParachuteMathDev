#pragma once
#include "./Vector2.h"
#include <typeinfo>
#include <iostream>

using namespace MathUtil;

Vector2::Vector2()
{
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

std::ostream &operator<<(std::ostream &os, const Vector2 &vec)
{
    return os << "[" << vec.x << ", " << vec.y << "]";
}