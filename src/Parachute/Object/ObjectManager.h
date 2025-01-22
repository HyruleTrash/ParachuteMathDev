#pragma once
#include <vector>
#include "./Object.cpp"

namespace Parachute
{
    class ObjectManager
    {
    private:
        std::vector<Object *> objects;

    public:
        ObjectManager();
        ~ObjectManager();
        void Update();
        void Initialize(Object *object);
        void Initialize(Object *object, Vector2 position);
    };
}
