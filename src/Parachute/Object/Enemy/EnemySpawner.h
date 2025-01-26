#pragma once
#include "../Object.h"
#include "./Enemy.cpp"

namespace Parachute
{
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