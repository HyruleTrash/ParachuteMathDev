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

Vector2 Bounds::GetClosestNormal(Vector2 aPos, Vector2 bPos, Bounds &bBounds)
{
    Bounds aBounds = Bounds{this};
    Vector2 sidesA[] = {
        Vector2{aPos + aBounds.L_Side},
        Vector2{aPos + aBounds.R_Side},
        Vector2{aPos + aBounds.T_Side},
        Vector2{aPos + aBounds.B_Side},
    };
    Vector2 sidesB[] = {
        Vector2{bPos + bBounds.L_Side},
        Vector2{bPos + bBounds.R_Side},
        Vector2{bPos + bBounds.T_Side},
        Vector2{bPos + bBounds.B_Side},
    };
    Vector2 sides[] = {
        Vector2{aBounds.L_Side},
        Vector2{aBounds.R_Side},
        Vector2{aBounds.T_Side},
        Vector2{aBounds.B_Side},
        Vector2{bBounds.L_Side},
        Vector2{bBounds.R_Side},
        Vector2{bBounds.T_Side},
        Vector2{bBounds.B_Side},
    };

    if (aPos.y + aBounds.B_Side.y > bPos.y + bBounds.T_Side.y &&
        aPos.y + aBounds.T_Side.y < bPos.y + bBounds.T_Side.y)
    {
        return V2_DOWN;
    }
    else if (aPos.y + aBounds.T_Side.y < bPos.y + bBounds.B_Side.y &&
             aPos.y + aBounds.B_Side.y > bPos.y + bBounds.B_Side.y)
    {
        return V2_UP;
    }
    if (aPos.x + aBounds.R_Side.x > bPos.x + bBounds.L_Side.x &&
        aPos.x + aBounds.L_Side.x < bPos.x + bBounds.L_Side.x)
    {
        return V2_RIGHT;
    }
    else if (aPos.x + aBounds.L_Side.x < bPos.x + bBounds.R_Side.x &&
             aPos.x + aBounds.R_Side.x > bPos.x + bBounds.R_Side.x)
    {
        return V2_LEFT;
    }
    return V2_ZERO;
}