#pragma once
#include "../Body.cpp"

namespace Parachute
{
    class StaticBody : public Body
    {
    private:
    public:
        StaticBody() = default;
        ~StaticBody() = default;
        void Update() override;
        double GetDensity() override;
    };
}