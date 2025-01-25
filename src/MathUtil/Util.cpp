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

    double RadianToDegree(double radian)
    {
        return radian * (180 / M_PI);
    }

    Vector2 DegreeToVector(double degree, double magnitude)
    {
        Vector2 result{};
        result.x = magnitude * cos(DegreeToRadian(degree));
        result.y = magnitude * sin(DegreeToRadian(degree));
        return result;
    }

    Vector2 RadianToVector(double radian, double magnitude)
    {
        Vector2 result{};
        result.x = magnitude * cos(radian);
        result.y = magnitude * sin(radian);
        return result;
    }

    Vector2 DegreeToNormalVector(double degree)
    {
        const double magnitudeNormalVector{1};
        return DegreeToVector(degree, magnitudeNormalVector);
    }

    Vector2 RadianToNormalVector(double radian)
    {
        const double magnitudeNormalVector{1};
        return RadianToVector(radian, magnitudeNormalVector);
    }

    double VectorToDegree(Vector2 a)
    {
        return RadianToDegree(tan(a.x / a.y));
    }

    double VectorToRadian(Vector2 a)
    {
        return atan(a.y / a.x);
    }

    double GetDistance(Vector2 a, Vector2 b)
    {
        return Vector2{a - b}.GetMagnitude();
    }

    Vector2 GetDirection(Vector2 a, Vector2 b)
    {
        return Vector2{b - a}.Normalize();
    }

    double SnapDirectionToEightDirections(double val)
    {
        const double targets[] = {0, 1, -1, 0.5, -0.5};
        int n = sizeof(targets) / sizeof(targets[0]);

        double min_diff = INFINITY;
        double result;

        for (int i = 0; i < n; ++i)
        {
            double diff = std::abs(val - targets[i]);
            if (diff < min_diff)
            {
                min_diff = diff;
                result = targets[i];
            }
        }

        return result;
    }
}