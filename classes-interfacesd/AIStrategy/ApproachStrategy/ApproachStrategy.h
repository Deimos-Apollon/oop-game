//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_APPROACHSTRATEGY_H

#include "../AIStrategy.h"

#define OOP_GAME_APPROACHSTRATEGY_H


// aggressive strategy, move towards player and attack
class ApproachStrategy: public AIStrategy {
public:
    void step(Enemy *enemy, Player *player) override;
};


#endif //OOP_GAME_APPROACHSTRATEGY_H
