//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_AISTRATEGY_H
#include "../../entities/Creatures/Player/Player.h"
#include "../../entities/Creatures/Enemies/Enemy/Enemy.h"

#define OOP_GAME_AISTRATEGY_H


class AIStrategy {
public:
    virtual void step(Enemy* enemy, Player* player) {};
};


#endif //OOP_GAME_AISTRATEGY_H
