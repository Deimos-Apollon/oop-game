//
// Created by Deimos on 09.10.2021.
//

#ifndef OOP_GAME_ENEMY_H

#include "../../Creature.h"
#include "../../Player/Player.h"


#define OOP_GAME_ENEMY_H

class AIStrategy;

class Enemy : public Creature {
    AIStrategy* strategy = nullptr;
public:
    Enemy(Field *field = nullptr, Cell *cell = nullptr, unsigned int hp_p = 0, int armor_p = 0, unsigned int base_attack_damage = 0);
    Enemy(unsigned int hp_p = 0, int armor_p = 0, unsigned int base_attack_damage = 0);
    void set_strategy(AIStrategy* new_strategy) { strategy = new_strategy; }
    AIStrategy* get_strategy() { return strategy; }
};


#endif //OOP_GAME_ENEMY_H
