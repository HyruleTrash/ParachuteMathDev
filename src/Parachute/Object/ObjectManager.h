#pragma once
#include <vector>
#include "./Object.cpp"

namespace Parachute
{
    class ObjectManager
    {
    private:
        std::vector<Object> objects;
    public:
        ObjectManager();
        ~ObjectManager();
        void Update();
    };
}
