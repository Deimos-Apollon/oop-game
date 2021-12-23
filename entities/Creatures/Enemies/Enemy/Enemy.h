//
// Created by Deimos on 09.10.2021.
//

#ifndef OOP_GAME_ENEMY_H

#include "../../Creature/Creature.h"

#define STEP_COOLDOWN 5
#define OOP_GAME_ENEMY_H


class Enemy : public Creature {
    unsigned short step_cooldown = STEP_COOLDOWN;
public:
    Enemy(unsigned int hp_max_p = 0, unsigned int hp_curr_p = 0, int armor_p = 0,
          unsigned int base_attack_damage = 0, unsigned int attack_range = 1);
    bool try_do_step();
};


#endif //OOP_GAME_ENEMY_H
