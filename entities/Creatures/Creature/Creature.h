//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_CREATURE_H

#include "../../Entity/Entity.h"
#include <cmath>

#define OOP_GAME_CREATURE_H


class Creature : public Entity {
protected:
    unsigned int max_hp = 0;
    unsigned int curr_hp = 0;
    int armor = 0;
    unsigned int base_attack_damage = 1;
    unsigned int attack_range = 1;
    explicit Creature(unsigned int hp_max_p = 0, unsigned int hp_curr_p = 0, int armor_p = 0,
                      unsigned int base_attack_damage = 1, unsigned int attack_range = 1);
public:
    ~Creature() override = default;

    unsigned int get_attack_range() const { return attack_range; };
    unsigned int get_curr_hp() const { return curr_hp; }
    unsigned int get_max_hp() const { return max_hp; }
    unsigned int get_armor() const { return armor; }
    unsigned int get_basic_attack_damage() const { return base_attack_damage; }

    virtual void attack(Creature* other_creature, int drow, int dcol);
    virtual void get_damage(unsigned int damage);

    void restore_health(unsigned int d_hp);
};


#endif //OOP_GAME_CREATURE_H
