#include "./CollisionSystem.h"
#include "../Body/Body.h"
#include "CollisionSystem.h"

using namespace Parachute;

void CollisionSystem::Update(std::vector<Object *> objects)
{
    auto checkList = SortBasedOnDistance(objects);
    for (auto collisionTest : checkList)
    {
        CollisionTestResult resultData = collisionTest.TestAABB();
        if (resultData.result)
        {
            ApplyCollision(collisionTest.a, collisionTest.b, resultData);
        }
    }
}

std::vector<CollisionTest> CollisionSystem::SortBasedOnDistance(std::vector<Object *> objects)
{
    std::vector<CollisionTest> result{};
    for (size_t i = 0; i < objects.size(); i++)
    {
        Object *objectI = objects[i];
        // make sure only to check for bodies
        if (dynamic_cast<Body *>(objectI) == nullptr)
            continue;

        for (size_t j = 0; j < objects.size(); j++)
        {
            if (j == i)
                continue;

            Object *objectJ = objects[j];
            // make sure only to check for bodies
            if (dynamic_cast<Body *>(objectJ) == nullptr)
                continue;

            const double reachOffset{10};
            double sizeObjectI = objectI->size.GetMagnitude();
            double sizeObjectJ = objectJ->size.GetMagnitude();
            // Make distance calc
            double distance = MathUtil::GetDistance(objectI->position, objectJ->position);
            if (distance < sizeObjectI + reachOffset || distance < sizeObjectJ + reachOffset)
            {
                bool shouldAdd{true};
                for (auto collisionTest : result)
                {
                    if (
                        (collisionTest.a == objectI && collisionTest.b == objectJ) ||
                        (collisionTest.a == objectJ && collisionTest.b == objectI))
                    {
                        shouldAdd = false;
                        break;
                    }
                }
                if (shouldAdd)
                    result.push_back(CollisionTest{objectI, objectJ});
            }
        }
    }

    return result;
}

void CollisionSystem::ApplyCollision(Object *a, Object *b, CollisionTestResult resultData)
{
    Body *body = dynamic_cast<Body *>(a);
    if (body->isTrigger)
    {
    }
    else
    {
        double density = body->mass / body->size.GetCubicVolume();
    }
}