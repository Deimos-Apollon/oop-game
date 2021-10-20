//
// Created by Deimos on 19.10.2021.
//

#ifndef OOP_GAME_MAGEHEALER_H
#define OOP_GAME_MAGEHEALER_H

#include "../../Enemy/Enemy.h"

class MageHealer : public Enemy {
public:
    explicit MageHealer(unsigned int hp = 15, int armor = 0, unsigned int damage = 3, unsigned int attack_range = 3);
};


#endif //OOP_GAME_MAGEHEALER_H
