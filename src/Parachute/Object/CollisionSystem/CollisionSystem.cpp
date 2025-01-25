#include "./CollisionSystem.h"
#include "../Body/Body.h"

using namespace Parachute;

void CollisionSystem::Update(std::vector<Object *> objects)
{
    auto checkList = SortBasedOnDistance(objects);
    // test for collision and trigger logic
    for (auto collisionTest : checkList)
    {
        CollisionTestResult resultData = collisionTest.TestAABB();
        if (resultData.result)
        {
            Body *bodyA = dynamic_cast<Body *>(collisionTest.a);
            Body *bodyB = dynamic_cast<Body *>(collisionTest.b);
            bodyA->ApplyCollision(bodyB, resultData.collisionNormalB);
            bodyB->ApplyCollision(bodyA, resultData.collisionNormalA);
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