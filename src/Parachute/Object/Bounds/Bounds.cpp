#include "./bounds.h"

using namespace Parachute;

Bounds::Bounds(Bounds *other)
{
    TL_Corner = other->TL_Corner;
    TR_Corner = other->TR_Corner;
    BL_Corner = other->BL_Corner;
    BR_Corner = other->BR_Corner;
    R_Side = other->R_Side;
    L_Side = other->L_Side;
    B_Side = other->B_Side;
    T_Side = other->T_Side;
}

Bounds::Bounds(Vector2 size)
{
    TL_Corner = Vector2{0 - (size.x / 2), 0 - (size.y / 2)};
    TR_Corner = Vector2{0 + (size.x / 2), 0 - (size.y / 2)};
    BL_Corner = Vector2{0 - (size.x / 2), 0 + (size.y / 2)};
    BR_Corner = Vector2{0 + (size.x / 2), 0 + (size.y / 2)};
    R_Side = Vector2{0 + (size.x / 2), (double)0};
    L_Side = Vector2{0 - (size.x / 2), (double)0};
    B_Side = Vector2{(double)0, 0 + (size.y / 2)};
    T_Side = Vector2{(double)0, 0 - (size.y / 2)};
}

std::ostream &operator<<(std::ostream &os, const Bounds &bounds)
{
    return os << "[" << bounds.R_Side << ", " << bounds.L_Side << ", " << bounds.B_Side << ", " << bounds.T_Side << "]";
}

Bounds Parachute::Bounds::operator+(const Vector2 &other)
{
    Bounds result{this};
    result.TL_Corner += other;
    result.TR_Corner += other;
    result.BL_Corner += other;
    result.BR_Corner += other;
    result.R_Side += other;
    result.L_Side += other;
    result.B_Side += other;
    result.T_Side += other;
    return result;
}

/// @brief checks the distance between each side, and returns the normal of the closest one
/// sadly only works with cubes that all hold a equal lenght and width.
/// @param aPos
/// @param bPos
/// @return
Vector2 Bounds::GetClosestNormal(Vector2 aPos, Vector2 bPos)
{
    Vector2 sidesAndCorners[] = {
        // Vector2{aPos + this->TL_Corner},
        // Vector2{aPos + this->TR_Corner},
        // Vector2{aPos + this->BL_Corner},
        // Vector2{aPos + this->BR_Corner},
        Vector2{aPos + this->L_Side},
        Vector2{aPos + this->R_Side},
        Vector2{aPos + this->T_Side},
        Vector2{aPos + this->B_Side},
    };
    int positionArraySize = sizeof(sidesAndCorners) / sizeof(sidesAndCorners[0]);

    double distances[positionArraySize];
    double smallestDist{INFINITY};
    for (size_t i = 0; i < positionArraySize; i++)
    {
        distances[i] = GetDistance(bPos, sidesAndCorners[i]);
        smallestDist = std::min(distances[i], smallestDist);
    }
    for (size_t i = 0; i < positionArraySize; i++)
    {
        if (distances[i] == smallestDist)
        {
            return Vector2{sidesAndCorners[i] - aPos}.Normalize();
        }
    }
    return V2_ZERO;
}