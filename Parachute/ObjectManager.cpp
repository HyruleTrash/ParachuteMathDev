#include "ObjectManager.h"

#include <vector>

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    
    ObjectManager::~ObjectManager()
    {
        for (Object *object : objects)
        {
            delete object;
        }
    }

    void ObjectManager::Update()
    {
        // Check for collisions
        collisionSystem.Update(std::vector<Object *>{objects});
        // Run rendering and physics logics per object
        for (Object *object : objects)
        {
            if (object != nullptr && object->ShouldRun())
                object->Update();
        }

        CleanObjectsToBeDeleted();
    }

    // cleanup any objects that need to be deleted
    void ObjectManager::CleanObjectsToBeDeleted()
    {
        for (int i = objects.size() - 1; i >= 0; i--)
        {
            for (int j = objectsToBeDeleted.size() - 1; j >= 0; j--)
            {
                Object& candidateObj = *objects[i];
                Object& toBeDeleted = *objectsToBeDeleted[j];
                if (&toBeDeleted == &candidateObj)
                {
                    RemoveFromObjectVector(objects, objects[i]);
                    RemoveFromObjectVector(objectsToBeDeleted, objectsToBeDeleted[j]);
                    candidateObj.Delete();
                }
            }
        }
    }

    void ObjectManager::RemoveFromObjectVector(std::vector<Object *>& list, Object* toRemove)
    {
        auto it = std::find(list.begin(), list.end(), toRemove);
        if (it != list.end()) {
            list.erase(it);
        }
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
