#pragma once
#include "./Vector2/Vector2.cpp"

#pragma once

namespace MathUtil
{
    Vector2 Normalize(Vector2 a)
    {
        return a.Normalize();
    }

    double Dot(Vector2 a, Vector2 b)
    {
        return (a.x * b.x) + (a.y * b.y);
    }
}