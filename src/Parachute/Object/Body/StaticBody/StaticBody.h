#pragma once
#include "../../Object.cpp"

namespace Parachute
{
    class StaticBody : public Object
    {
    private:
    public:
        StaticBody();
        ~StaticBody();
        void Update() override;
    };
}