//
// Created by Deimos on 09.10.2021.
//

#include "Enemy.h"


Enemy::Enemy(unsigned int hp_p, int armor_p, unsigned int base_attack_damage, unsigned int attack_range) :
Creature(hp_p, armor_p, base_attack_damage, attack_range) {

}

bool Enemy::try_do_step() {
    if (step_cooldown == 0)
    {
        step_cooldown = STEP_COOLDOWN;
        return true;
    } else
    {
        --step_cooldown;
        return false;
    }
}


