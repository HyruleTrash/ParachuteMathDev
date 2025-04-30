#include "./CollisionSystem.h"
#include "Body.h"

namespace Parachute
{
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

    /// @brief To avoid checking unneeded object's sort them based on if they are even close enough to collide
    /// @param objects
    /// @return
    std::vector<CollisionTest> CollisionSystem::SortBasedOnDistance(std::vector<Object *> objects)
    {
        std::vector<CollisionTest> result{};
        for (size_t i = 0; i < objects.size(); i++)
        {
            Object *objectI = objects[i];
            // make sure only to check for bodies
            Body *bodyCheckI = dynamic_cast<Body *>(objectI);
            if (bodyCheckI == nullptr)
                continue;
            else if (bodyCheckI->collisionEnabled == false)
                continue;

            for (size_t j = 0; j < objects.size(); j++)
            {
                if (j == i)
                    continue;

                Object *objectJ = objects[j];
                // make sure only to check for bodies
                Body *bodyCheckJ = dynamic_cast<Body *>(objectJ);
                if (bodyCheckJ == nullptr)
                    continue;
                else if (bodyCheckJ->collisionEnabled == false)
                    continue;

                // add a offset for leeway
                double reachOffset{10};

                // account for the fact that physics bodies move
                double sizeObjectI = objectI->size.GetMagnitude() + bodyCheckI->CollisionOffset();
                double sizeObjectJ = objectJ->size.GetMagnitude() + bodyCheckJ->CollisionOffset();
                // Make distance calc
                double distance = MathUtil::Util::GetDistance(objectI->position, objectJ->position);
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
}