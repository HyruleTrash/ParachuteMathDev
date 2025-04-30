#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Body.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    
    Parachute::Body::Body(Body *other)
    {
        this->isTrigger = other->isTrigger;
        this->friction = other->friction;
        this->mass = other->mass;
        this->density = other->density;
        this->visible = other->visible;
        this->size = other->size;
        this->bounds = other->bounds;
        this->position = other->position;
    }

    void Body::Update()
    {
        if (isTrigger)
        {
            checkGameState = false;
            visible = false;
        }
        Object::Update();
        density = GetDensity();

        CleanUpCollision();

        // render object/box if visible
        if (visible)
        {
            sf::RectangleShape shape({(float)size.x, (float)size.y});
            shape.setFillColor(color);
            Vector2 origin{size / 2};
            shape.setOrigin({(float)origin.x, (float)origin.y});
            sf::Vector2f pos{(float)position.x, (float)position.y};
            shape.setPosition(pos);
            game->window.draw(shape);
        }
    }

    GameState Body::GetGameState()
    {
        return game->gameState;
    }

    /// @brief
    /*
        this is run at the start of the physics frame,
        you can consider it the end of the last frame really.
        we cleanup some data, so that it can be used again.
    */
    void Body::CleanUpCollision()
    {
        std::vector<IntersectionData> NoLongerIntersecting;
        for (auto bodyOld : intersectingBodiesPreviousFrame)
        {
            bool found = false;
            for (size_t i = 0; i < intersectingBodies.size(); i++)
            {
                auto body = intersectingBodies[i];
                if (body.intersectorPtr == bodyOld.intersectorPtr)
                {
                    found = true;
                    break;
                }
            }

            // Add bodies that were present in previous frame but not in current frame
            if (!found)
            {
                NoLongerIntersecting.push_back(bodyOld);
            }
        }

        for (auto data : NoLongerIntersecting)
        {
            ApplyCollisionExit(data);
        }

        intersectingBodiesPreviousFrame = {intersectingBodies};
        intersectingBodies = {};
    }

    /// @brief Tells the relevant bodies that they are no longer intersecting
    /// @param data
    void Body::ApplyCollisionExit(IntersectionData data)
    {
        Body *other = dynamic_cast<Body *>(data.intersectorPtr);
        if (isTrigger)
        {
            OnTriggerExited(other, data);
        }
        else
        {
            OnCollisionEnded(other, data);
        }
    }

    /// @brief Based on if it was already touching, or just touched once, triggers different collision functions
    /// @param other
    /// @param collisionNormal
    void Body::ApplyCollision(Body *other, Vector2 collisionNormal)
    {
        bool isAlreadyIntersectingPreviousFrame{false};
        bool isAlreadyIntersectingThisFrame{false};
        for (auto body : intersectingBodiesPreviousFrame)
        {
            if (body.intersectorPtr == other)
            {
                isAlreadyIntersectingPreviousFrame = true;
                break;
            }
        }
        for (auto body : intersectingBodies)
        {
            if (body.intersectorPtr == other)
            {
                isAlreadyIntersectingThisFrame = true;
                break;
            }
        }

        if (isAlreadyIntersectingThisFrame == false)
        {
            intersectingBodies.push_back(IntersectionData{other, new Body{other}, collisionNormal});
            if (isAlreadyIntersectingPreviousFrame == false)
            {
                if (isTrigger)
                {
                    OnTriggerEntered(other);
                }
                else
                {
                    OnCollided(other, collisionNormal);
                }
            }
            else
            {
                if (!isTrigger)
                {
                    OnColliding(other, collisionNormal);
                }
            }
        }
    }

    /// @brief When the intersection has ended between two objectsm the old data should be deleted
    /// @param other
    /// @param data
    void Body::OnTriggerExited(Body *other, IntersectionData data)
    {
        delete data.intersectorOldData;
    }

    /// @brief When the intersection has ended between two objectsm the old data should be deleted
    /// @param other
    /// @param data
    void Body::OnCollisionEnded(Body *other, IntersectionData data)
    {
        delete data.intersectorOldData;
    }

    /// @brief Calculates the body's density based on its mass and volume
    /// @return
    double Body::GetDensity()
    {
        return mass / size.GetCubicVolume();
    }
}