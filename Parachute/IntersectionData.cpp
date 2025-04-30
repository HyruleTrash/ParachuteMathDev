#include "./IntersectionData.h"
#include "IntersectionData.h"

namespace Parachute
{
    IntersectionData::IntersectionData(Body *intersectorPtr, Body *intersectorOldData, Vector2 appliedNormalVector)
    {
        this->intersectorPtr = intersectorPtr;
        this->intersectorOldData = intersectorOldData;
        this->appliedNormalVector = appliedNormalVector;
    }
}