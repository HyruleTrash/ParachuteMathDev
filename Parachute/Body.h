#pragma once
#include "GameState.h"
#include "Object.h"
#include "IntersectionData.h"
#include "../MathUtil/Vector2.h"
#include "Game.h"

namespace Parachute
{
    /// @brief Base physics object, holds information that all physics type objects share
    class Body : public Object
    {
    private:
        std::vector<IntersectionData> intersectingBodiesPreviousFrame{};
        std::vector<IntersectionData> intersectingBodies{};

    public:
        Body() = default;
        Body(Body *);
        ~Body() = default;
        void Update() override;
        GameState GetGameState() override;
        void CleanUpCollision();
        virtual double CollisionOffset() { return 0.0; }; // adds a offset for collision distance sorting
        void ApplyCollisionExit(const IntersectionData&);
        void ApplyCollision(Body *other, MathUtil::Vector2 collisionNormal);
        virtual void OnTriggerEntered(Body *other) {};                     // called when a body enters the trigger
        virtual void OnTriggerExited(Body* other, const IntersectionData&) {};       // called when a body has left the trigger
        virtual void OnCollided(Body *other, MathUtil::Vector2 collisionNormal) {};  // called when a body enters the collider for the first time
        virtual void OnColliding(Body *other, MathUtil::Vector2 collisionNormal) {}; // called when a body is inside of a collider
        virtual void OnCollisionEnded(Body* other, const IntersectionData&) {};      // called when a body has left the collider
        virtual double GetDensity();
        bool collisionEnabled{true};
        sf::Color color{sf::Color::Blue};
        bool isTrigger{false};
        double density{};
        float mass{1};
        float friction{0.5};
    };
}