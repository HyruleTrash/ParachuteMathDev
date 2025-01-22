#pragma once
#include "./ObjectManager.h"

using namespace Parachute;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
    for (Object *object : objects)
    {
        delete object;
    }
}

void ObjectManager::Update()
{
    for (Object *object : objects)
    {
        object->Update();
    }
}

void ObjectManager::Initialize(Object *object)
{
    objects.push_back(object);
}

void ObjectManager::Initialize(Object *object, Vector2 position)
{
    object->position = position;
    Initialize(object);
}