//
// Created by Deimos on 20.10.2021.
//

#include "StrategiesManager.h"



StrategiesManager::StrategiesManager() {
    strategies = {
            {"MeleeSkeletonAgressiveStrategy", new MeleeSkeletonAgressiveStrategy},
            {"ArcherSkeletonStrategy", new ArcherSkeletonStrategy},
            {"MageHealerStrategy", new MageHealerStrategy},
    };
}

void StrategiesManager::enemy_set_strategy(Enemy *enemy, string strategy_name) {
    if (strategies.find(strategy_name) != strategies.end())
    {
        enemy_strategies.insert({enemy, strategies[strategy_name]});
    }
}

void StrategiesManager::enemies_set_strategies(map <Enemy*, pair<unsigned int, unsigned int>> &enemies) {
    map <std::string, std::string> setting_strategies = {
            {typeid(MeleeSkeleton).name(), "MeleeSkeletonAgressiveStrategy"},
            {typeid(ArcherSkeleton).name(), "ArcherSkeletonStrategy"},
            {typeid(MageHealer).name(),"MageHealerStrategy"},
    };
    for (auto enemy_pair: enemies)
    {
        auto enemy = enemy_pair.first;
        enemy_set_strategy(enemy, setting_strategies[typeid(*enemy).name()]);
    }
}

void StrategiesManager::enemy_remove(Enemy *enemy) {
    enemy_strategies.erase(enemy);
}

void StrategiesManager::step(FieldInterface *field, Enemy *enemy, Player *player) {
    enemy_strategies[enemy]->step(field, enemy, player);
}

