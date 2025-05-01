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
        IntersectionData(Body *intersectorPtr, std::shared_ptr<Body> intersectorOldData, MathUtil::Vector2 appliedNormalVector);
        ~IntersectionData() = default;
        Body *intersectorPtr;
        std::shared_ptr<Body> intersectorOldData;
        MathUtil::Vector2 appliedNormalVector;
    };
}