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

Vector2 Bounds::GetClosestNormal(Vector2 aPos, Vector2 bPos, Bounds *bBounds)
{
    Vector2 sidesA[] = {
        Vector2{aPos + this->L_Side},
        Vector2{aPos + this->R_Side},
        Vector2{aPos + this->T_Side},
        Vector2{aPos + this->B_Side},
    };
    Vector2 sidesB[] = {
        Vector2{bPos + bBounds->L_Side},
        Vector2{bPos + bBounds->R_Side},
        Vector2{bPos + bBounds->T_Side},
        Vector2{bPos + bBounds->B_Side},
    };
    Vector2 sides[] = {
        Vector2{this->L_Side},
        Vector2{this->R_Side},
        Vector2{this->T_Side},
        Vector2{this->B_Side},
        Vector2{bBounds->L_Side},
        Vector2{bBounds->R_Side},
        Vector2{bBounds->T_Side},
        Vector2{bBounds->B_Side},
    };
    int positionArraySize = sizeof(sides) / sizeof(sides[0]);

    double distances[positionArraySize];
    double smallestDist{INFINITY};
    int index = 0;
    for (Vector2 sideA : sidesA)
    {
        index++;
        for (Vector2 sideB : sidesB)
        {
            distances[index] = GetDistance(sidesB, sideA);
            smallestDist = std::min(distances[index], smallestDist);
        }
    }

    index = 0;
    for (double distance : distances)
    {
        index++;
        if (distance == smallestDist)
        {
            return Vector2{sides[index]}.Normalize();
        }
    }
    return V2_ZERO;
}