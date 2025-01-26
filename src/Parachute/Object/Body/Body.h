#pragma once
#include "../Object.cpp"
#include "./IntersectionData/IntersectionData.cpp"

namespace Parachute
{
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
        void CleanUpCollision();
        void ApplyCollisionExit(IntersectionData);
        void ApplyCollision(Body *other, Vector2 collisionNormal);
        virtual void OnTriggerEntered(Body *other) {};
        virtual void OnTriggerExited(Body *other, IntersectionData);
        virtual void OnCollided(Body *other, Vector2 collisionNormal) {};
        virtual void OnColliding(Body *other, Vector2 collisionNormal) {};
        virtual void OnCollisionEnded(Body *other, IntersectionData);
        virtual double GetDensity();
        bool isTrigger{false};
        double density{};
        float mass{1};
        float friction{0.5};
    };
}