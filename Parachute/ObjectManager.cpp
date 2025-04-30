#include "ObjectManager.h"

namespace Parachute
{
    ObjectManager::~ObjectManager()
    {
        for (Object *object : objects)
        {
            delete object;
        }
    }

    void ObjectManager::Update()
    {
        // Run rendering and physics logics per object
        for (Object *object : objects)
        {
            object->Update();
        }
        // Check for collisions
        collisionSystem.Update(std::vector<Object *>{objects});

        // cleanup any objects that need to be deleted
        for (int i = objects.size() - 1; i >= 0; i--)
        {
            for (Object *toBeDeleted : objectsToBeDeleted)
            {
                if (toBeDeleted == objects[i])
                    objects.erase(objects.begin() + i);
            }
        }
        objectsToBeDeleted.clear();
    }

    /// @brief Tells the manager that all current objects need to be deleted later
    void ObjectManager::ClearObjects()
    {
        for (Object *object : objects)
        {
            Delete(object);
        }
    }

    /// @brief adds a object reference to the should be removed/deleted list
    /// @param object
    void ObjectManager::Delete(Object *object)
    {
        objectsToBeDeleted.push_back(object);
    }

    /// @brief Adds a reference to the list of all game objects that this manager keeps track off
    /// @param object
    void ObjectManager::Initialize(Object *object)
    {
        if (object != nullptr)
            objects.push_back(object);
    }

    /// @brief Adds a reference to the list of all game objects that this manager keeps track off
    /// And sets its position
    /// @param object
    /// @param position
    void ObjectManager::Initialize(Object *object, Vector2 position)
    {
        object->position = position;
        Initialize(object);
    }
}