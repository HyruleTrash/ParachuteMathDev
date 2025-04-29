#pragma once
#include "Vector2.h"

namespace MathUtil
{
    class Util {
    public:
        static Vector2 Normalize(Vector2 a);
        static double GetMagnitude(Vector2 a);
        static double Dot(Vector2 a, Vector2 b);
        static double DegreeToRadian(double degree);
        static double RadianToDegree(double radian);
        static Vector2 DegreeToVector(double degree, double magnitude);
        static Vector2 RadianToVector(double radian, double magnitude);
        static Vector2 DegreeToNormalVector(double degree);
        static Vector2 RadianToNormalVector(double radian);
        static double VectorToDegree(Vector2 a);
        static double VectorToRadian(Vector2 a);
        static double GetDistance(Vector2 a, Vector2 b);
        static Vector2 GetDirection(Vector2 a, Vector2 b);
        static double SnapDirectionToEightDirections(double val);
    };
}
