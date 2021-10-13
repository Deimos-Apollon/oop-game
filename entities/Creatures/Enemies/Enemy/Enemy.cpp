//
// Created by Deimos on 09.10.2021.
//

#include "Enemy.h"

Enemy::Enemy(Field *field, Cell *cell, unsigned int hp_p, int armor_p, unsigned int base_attack_damage) : Creature(
        field, cell, hp_p, armor_p, base_attack_damage) {

}

Enemy::Enemy(unsigned int hp_p, int armor_p, unsigned int base_attack_damage) : Creature(hp_p, armor_p,
                                                                                         base_attack_damage) {

}
