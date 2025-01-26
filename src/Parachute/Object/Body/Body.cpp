#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Body.h"
#include "../../Game/Game.h"
#include "Body.h"

using namespace Parachute;

Parachute::Body::Body(Body *other)
{
    this->isTrigger = other->isTrigger;
    this->friction = other->friction;
    this->mass = other->mass;
    this->density = other->density;
    this->visable = other->visable;
    this->size = other->size;
    this->bounds = other->bounds;
    this->position = other->position;
}

void Body::Update()
{
    Object::Update();
    density = GetDensity();

    CleanUpCollision();

    if (visable)
    {
        sf::RectangleShape shape({(float)size.x, (float)size.y});
        shape.setFillColor(sf::Color::Green);
        Vector2 origin{size / 2};
        shape.setOrigin({(float)origin.x, (float)origin.y});
        sf::Vector2f pos{(float)position.x, (float)position.y};
        shape.setPosition(pos);
        game->window.draw(shape);
    }

    // temp looping
    if (position.x + bounds.L_Side.x >= game->GetResolution().x)
        position.x = 0 + bounds.L_Side.x;
    if (position.x + bounds.R_Side.x < 0 + bounds.L_Side.x)
        position.x = game->GetResolution().x + bounds.R_Side.x;
    if (position.y + bounds.T_Side.y >= game->GetResolution().y)
        position.y = 0 + bounds.T_Side.y;
    if (position.y + bounds.B_Side.y < 0 + bounds.T_Side.y)
        position.y = game->GetResolution().y + bounds.B_Side.y;
}

void Body::CleanUpCollision()
{
    /*
    this is run at the start of the physics frame,
    you can consider it the end of the last frame really.
    we cleanup some data, so that it can be used again.
    */
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

void Body::OnTriggerExited(Body *other, IntersectionData data)
{
    delete data.intersectorOldData;
}

void Body::OnCollisionEnded(Body *other, IntersectionData data)
{
    delete data.intersectorOldData;
}

double Body::GetDensity()
{
    return mass / size.GetCubicVolume();
}
