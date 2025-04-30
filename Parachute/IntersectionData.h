#pragma once
#include "../MathUtil/Util.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    class Body;

    /// @brief Holds interaction data, mostly used for retrieving old collision data
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