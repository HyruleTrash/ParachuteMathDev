#pragma once
#include "../MathUtil/Vector2.h"

namespace Parachute
{
    /// @brief Holds bounding box information, and is calculated based on object size
    class Bounds
    {
    public:
        Bounds() = default;
        Bounds(Bounds *);
        Bounds(MathUtil::Vector2 size);
        ~Bounds() = default;
        Bounds operator+(const MathUtil::Vector2 &other);
        MathUtil::Vector2 GetClosestNormal(MathUtil::Vector2 aPos, MathUtil::Vector2 bPos);
        MathUtil::Vector2 TL_Corner{};
        MathUtil::Vector2 TR_Corner{};
        MathUtil::Vector2 BL_Corner{};
        MathUtil::Vector2 BR_Corner{};
        MathUtil::Vector2 L_Side{};
        MathUtil::Vector2 R_Side{};
        MathUtil::Vector2 T_Side{};
        MathUtil::Vector2 B_Side{};
    };
}
