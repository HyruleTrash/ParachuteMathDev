#pragma once
#include "../Object.cpp"

namespace Parachute
{
    class Body : public Object
    {
    private:
    public:
        Body();
        ~Body();
        void Update() override;
    };
}