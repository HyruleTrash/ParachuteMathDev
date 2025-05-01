#pragma once
#include <vector>
#include "Object.h"
#include "CollisionSystem.h"

namespace Parachute
{
    /// @brief Keeps track of all game objects
    class ObjectManager
    {
    private:
        std::vector<Object *> objects;
        std::vector<Object *> objectsToBeDeleted;
        CollisionSystem collisionSystem{};

    public:
        ObjectManager() = default;
        ~ObjectManager();
        void Update();
        void CleanObjectsToBeDeleted();
        void RemoveFromObjectVector(std::vector<Object*>& list, Object* toRemove);
        void ClearObjects();
        void Delete(Object *);
        void Initialize(Object *object);
        void Initialize(Object *object, MathUtil::Vector2 position);
    };
}
