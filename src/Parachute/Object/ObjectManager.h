#pragma once
#include <vector>
#include "./Object.cpp"
#include "./CollisionSystem/CollisionSystem.cpp"

namespace Parachute
{
    class ObjectManager
    {
    private:
        std::vector<Object *> objects;
        CollisionSystem collisionSystem{};

    public:
        ObjectManager() = default;
        ~ObjectManager();
        void Update();
        void Initialize(Object *object);
        void Initialize(Object *object, Vector2 position);
    };
}
