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
        Vector2(double x, double y);
        ~Vector2();
        Vector2 &operator=(const Vector2 &other);
        double x = 0;
        double y = 0;
    };
}