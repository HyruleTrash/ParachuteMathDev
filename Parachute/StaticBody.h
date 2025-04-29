#pragma once
#include <iostream>
#include "Body.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    
    class StaticBody : public Body
    {
    private:
    public:
        StaticBody() = default;
        StaticBody(Vector2 size, Game *);
        ~StaticBody() = default;
        void Update() override;
        double GetDensity() override;
    };
}