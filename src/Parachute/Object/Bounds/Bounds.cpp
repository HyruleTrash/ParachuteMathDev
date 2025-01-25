#include "./bounds.h"

using namespace Parachute;

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

Vector2 Bounds::GetClosestNormal(Vector2 aPos, Vector2 bPos)
{
    Vector2 sidesAndCorners[] = {
        Vector2{aPos + this->TL_Corner},
        Vector2{aPos + this->TR_Corner},
        Vector2{aPos + this->BL_Corner},
        Vector2{aPos + this->BR_Corner},
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