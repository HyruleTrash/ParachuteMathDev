#include "./IntersectionData.h"
#include "IntersectionData.h"
#include "Body.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    
    IntersectionData::IntersectionData(Body *intersectorPtr, std::shared_ptr<Body> intersectorOldData, Vector2 appliedNormalVector)
    {
        this->intersectorPtr = intersectorPtr;
        this->intersectorOldData = std::move(intersectorOldData);
        this->appliedNormalVector = appliedNormalVector;
    }
}