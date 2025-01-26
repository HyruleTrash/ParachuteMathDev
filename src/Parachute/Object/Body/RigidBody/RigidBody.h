#pragma once
#include "../Body.cpp"

namespace Parachute
{
    class Force
    {
    public:
        Force() = default;
        Force(Force *);
        Force(Vector2 force, Body *other);
        ~Force() = default;
        static Vector2 GetSum(std::vector<Force> &);
        static bool Contains(std::vector<Force> &, Vector2 force, Body *other);
        static void RemoveNegated(std::vector<Force> &);
        Vector2 force{};
        Body *other{};
    };

    class RigidBody : public Body
    {
    private:
        constexpr static Vector2 MAX_VELOCITY{200, 200};
        std::vector<Force> forces{};
        std::vector<Force> impulses{};

    public:
        RigidBody() = default;
        ~RigidBody() = default;
        void Update() override;
        void AddForce(Vector2 force);
        void AddImpulse(Vector2 impulse);
        void AddForce(Vector2 force, Body *other);
        void AddImpulse(Vector2 impulse, Body *other);
        void OnCollided(Body *other, Vector2 collisionNormal);
        void OnCollisionEnded(Body *other, IntersectionData);
        Vector2 velocity{V2_ZERO};
    };
}