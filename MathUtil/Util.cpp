#define _USE_MATH_DEFINES
#include <cmath>
#include <random>
#include <string>
#include "Util.h"

namespace MathUtil
{
    Vector2 Util::Normalize(Vector2 a)
    {
        return a.Normalize();
    }

    double Util::GetMagnitude(Vector2 a)
    {
        return Vector2{a}.GetMagnitude();
    }

    double Util::Dot(Vector2 a, Vector2 b)
    {
        return (a.x * b.x) + (a.y * b.y);
    }

    double Util::DegreeToRadian(double degree)
    {
        return degree * (M_PI / 180);
    }

    double Util::RadianToDegree(double radian)
    {
        return radian * (180 / M_PI);
    }

    Vector2 Util::DegreeToVector(double degree, double magnitude)
    {
        Vector2 result{};
        result.x = magnitude * cos(DegreeToRadian(degree));
        result.y = magnitude * sin(DegreeToRadian(degree));
        return result;
    }

    Vector2 Util::RadianToVector(double radian, double magnitude)
    {
        Vector2 result{};
        result.x = magnitude * cos(radian);
        result.y = magnitude * sin(radian);
        return result;
    }

    Vector2 Util::DegreeToNormalVector(double degree)
    {
        const double magnitudeNormalVector{1};
        return DegreeToVector(degree, magnitudeNormalVector);
    }

    Vector2 Util::RadianToNormalVector(double radian)
    {
        const double magnitudeNormalVector{1};
        return RadianToVector(radian, magnitudeNormalVector);
    }

    double Util::VectorToDegree(Vector2 a)
    {
        return RadianToDegree(tan(a.x / a.y));
    }

    double Util::VectorToRadian(Vector2 a)
    {
        return atan(a.y / a.x);
    }

    double Util::GetDistance(Vector2 a, Vector2 b)
    {
        return Vector2{a - b}.GetMagnitude();
    }

    Vector2 Util::GetDirection(Vector2 a, Vector2 b)
    {
        return Vector2{b - a}.Normalize();
    }

    /// @brief Returns a random double value with the set minimum and maximum constraints
    /// @param min
    /// @param max
    /// @return
    double Util::RandomRange(double min, double max)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    /// @brief Returns a string, filled with the given number n. and fills up the remaining space with zeros
    /// @param n
    /// @param length
    /// @return
    std::string Util::IntToStringWithZeros(int num, int length)
    {
        std::string str = std::to_string(abs(num));
        while (str.length() < length)
            str = "0" + str;
        if (num < 0)
            str = "-" + str;
        return str;
    }
}
