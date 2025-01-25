#pragma once
#include <memory>
#include "../../../../MathUtil/Util.cpp"

namespace Parachute
{
    class Body;

    class IntersectionData
    {
    public:
        IntersectionData() = default;
        IntersectionData(Body *intersectorPtr, Body *intersectorOldData, Vector2 appliedNormalVector);
        Body *intersectorPtr;
        Body *intersectorOldData;
        Vector2 appliedNormalVector;
    };
}