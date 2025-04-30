#pragma once
#include "RigidBody.h"
#include "Player.h"

namespace Parachute
{
    /// @brief Enemy that the player must avoid, removes points upon contact
    class Enemy : public RigidBody
    {
    private:
        constexpr static MathUtil::Vector2 DEFAULT_ENEMY_SIZE{40, 40};
        constexpr static float DEFAULT_ENEMY_MASS{5};
        constexpr static sf::Color colors[]{sf::Color{139, 58, 94}, sf::Color{167, 68, 142}, sf::Color{196, 40, 76}, sf::Color{116, 0, 58}};
        std::chrono::time_point<std::chrono::high_resolution_clock> spawnTimeStamp;

    public:
        Enemy();
        Enemy(Game *);
        ~Enemy() = default;
        void Update() override;
        void OnColliding(Body *other, MathUtil::Vector2 collisionNormal) override;
        void OnCollided(Body *other, MathUtil::Vector2 collisionNormal) override;
        MathUtil::Vector2 speed{300, 500};
        bool directionLeft;
        double wakeUpThreshold{0.1};
    };
}