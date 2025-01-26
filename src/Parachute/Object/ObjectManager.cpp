#pragma once
#include "./ObjectManager.h"

using namespace Parachute;

ObjectManager::~ObjectManager()
{
    for (Object *object : objects)
    {
        delete object;
    }
}

void ObjectManager::Update()
{
    collisionSystem.Update(std::vector<Object *>{objects});
    for (Object *object : objects)
    {
        object->Update();
    }

    // cleanup
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

void ObjectManager::ClearObjects()
{
    for (Object *object : objects)
    {
        Delete(object);
    }
}

void ObjectManager::Delete(Object *object)
{
    objectsToBeDeleted.push_back(object);
}

void ObjectManager::Initialize(Object *object)
{
    if (object != nullptr)
        objects.push_back(object);
}

void ObjectManager::Initialize(Object *object, Vector2 position)
{
    object->position = position;
    Initialize(object);
}