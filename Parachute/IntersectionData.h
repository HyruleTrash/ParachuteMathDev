#pragma once
#include "../MathUtil/Util.h"

namespace Parachute
{
    class Body;

    /// @brief Holds interaction data, mostly used for retrieving old collision data
    class IntersectionData
    {
    public:
        IntersectionData() = default;
        IntersectionData(Body *intersectorPtr, Body *intersectorOldData, MathUtil::Vector2 appliedNormalVector);
        Body *intersectorPtr;
        Body *intersectorOldData;
        MathUtil::Vector2 appliedNormalVector;
    };
}