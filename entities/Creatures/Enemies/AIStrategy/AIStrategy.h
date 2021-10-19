//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_AISTRATEGY_H

#define OOP_GAME_AISTRATEGY_H

#include "../../../../field/FieldInterface/FieldInterface.h"

class AIStrategy {
public:
    virtual void step(FieldInterface* field, Enemy* enemy, Player* player) {};
};


#endif //OOP_GAME_AISTRATEGY_H
