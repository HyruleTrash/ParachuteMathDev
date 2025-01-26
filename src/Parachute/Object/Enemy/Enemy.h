#pragma once
#include "../Body/RigidBody/RigidBody.h"

namespace Parachute
{
    class Enemy : public RigidBody
    {
    private:
        constexpr static Vector2 DEFAULT_ENEMY_SIZE{40, 40};
        constexpr static float DEFAULT_ENEMY_MASS{5};
        constexpr static sf::Color colors[]{sf::Color::Red, sf::Color::Green, sf::Color::Magenta, sf::Color::Cyan};
        std::chrono::time_point<std::chrono::high_resolution_clock> spawnTimeStamp;

    public:
        Enemy();
        Enemy(Game *);
        ~Enemy() = default;
        void Update() override;
        double speed{200};
        double wakeUpThreshold{2};
    };
}