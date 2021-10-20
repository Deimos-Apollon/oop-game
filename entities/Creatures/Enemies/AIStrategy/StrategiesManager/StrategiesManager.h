//
// Created by Deimos on 20.10.2021.
//

#ifndef OOP_GAME_STRATEGIESMANAGER_H
#define OOP_GAME_STRATEGIESMANAGER_H


#include "../../Enemy/Enemy.h"
#include "../AIStrategy.h"
#include "../../Enemies_types/MeleeSkeleton/MeleeSkeleton.h"
#include "../../Enemies_types/ArcherSkeleton/ArcherSkeleton.h"
#include "../../Enemies_types/MageHealer/MageHealer.h"
#include "../MeleeSkeletonAgressiveStrategy/MeleeSkeletonAgressiveStrategy.h"
#include "../MageHealerStrategy/MageHealerStrategy.h"
#include "../ArcherSkeletonStrategy/ArcherSkeletonStrategy.h"

#include <string>
#include <map>
#include <typeinfo>

class StrategiesManager {
    map <string, AIStrategy*> strategies;
    map <Enemy*, AIStrategy*> enemy_strategies;
private:
    void enemy_set_strategy(Enemy* enemy, string strategy_name);
public:
    StrategiesManager();

    void enemies_set_strategies(map <Enemy*, pair<unsigned int, unsigned int>> &enemies);
    void enemy_remove(Enemy* enemy);
    void step(FieldInterface* field, Enemy* enemy, Player* player);
};


#endif //OOP_GAME_STRATEGIESMANAGER_H
