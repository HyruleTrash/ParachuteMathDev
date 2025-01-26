#pragma once
#include "../../../MathUtil/Util.cpp"

namespace Parachute
{
    class Bounds
    {
    public:
        Bounds() = default;
        Bounds(Vector2 size);
        ~Bounds() = default;
        Vector2 GetClosestNormal(Vector2 aPos, Vector2 bPos, Bounds *bBounds);
        Vector2 TL_Corner{};
        Vector2 TR_Corner{};
        Vector2 BL_Corner{};
        Vector2 BR_Corner{};
        Vector2 L_Side{};
        Vector2 R_Side{};
        Vector2 T_Side{};
        Vector2 B_Side{};
    };
}
