#pragma once
#include "./Vector2/Vector2.cpp"
#include <cmath>

#pragma once

namespace MathUtil
{
    Vector2 Normalize(Vector2 a)
    {
        return a.Normalize();
    }

    double GetMagnitude(Vector2 a)
    {
        return Vector2{a}.GetMagnitude();
    }

    double Dot(Vector2 a, Vector2 b)
    {
        return (a.x * b.x) + (a.y * b.y);
    }

    double DegreeToRadian(double degree)
    {
        return degree * (M_PI / 180);
    }

    Vector2 DegreeToVector(double degree, double magnitude)
    {
        Vector2 result{};
        result.x = magnitude * cos(DegreeToRadian(degree));
        result.y = magnitude * sin(DegreeToRadian(degree));
        return result;
    }

    Vector2 DegreeToNormalVector(double degree)
    {
        const double magnitudeNormalVector{1};
        return DegreeToVector(degree, magnitudeNormalVector);
    }

    Vector2 GetNextVelocity(Vector2 initialVelocity, Vector2 totalForce, double mass)
    {
        Vector2 acceleration{totalForce / mass};
        std::cout << "[" << initialVelocity << "," << totalForce << "," << mass << "," << acceleration << std::endl;
        return Vector2{initialVelocity + acceleration};
    }

    Vector2 GetPositionOffset(Vector2 nextVelocity, Vector2 initialVelocity, double time)
    {
        return Vector2{((nextVelocity + initialVelocity) / 2) * time};
    }
}