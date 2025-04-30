#include "./IntersectionData.h"
#include "IntersectionData.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    
    IntersectionData::IntersectionData(Body *intersectorPtr, Body *intersectorOldData, Vector2 appliedNormalVector)
    {
        this->intersectorPtr = intersectorPtr;
        this->intersectorOldData = intersectorOldData;
        this->appliedNormalVector = appliedNormalVector;
    }
}