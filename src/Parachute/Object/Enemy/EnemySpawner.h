#pragma once
#include "../Object.h"
#include "./Enemy.cpp"

namespace Parachute
{
    /// @brief Spawns a enemy through the object manager, based on a timer that uses deltaTime
    class EnemySpawner : public Object
    {
    private:
        double timer{0};

    public:
        EnemySpawner() = default;
        EnemySpawner(Game *);
        ~EnemySpawner() = default;
        void Update() override;
        GameState GetGameState() override;
        double spawnInterval{2};
        double spawnOffset{50};
    };
}