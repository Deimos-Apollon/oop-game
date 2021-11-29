//
// Created by deimos on 20.09.2021.
//

#include "Creature.h"


Creature::Creature(unsigned int hp_p, int armor_p, unsigned int base_attack_damage, unsigned int attack_range):
     max_hp(hp_p), curr_hp(hp_p), armor(armor_p), base_attack_damage(base_attack_damage), attack_range(attack_range) {

}


void Creature::attack(Creature *other_creature,  int drow,  int dcol) {
    if (abs(drow) <= attack_range && abs(dcol) <= attack_range) {
        other_creature->get_damage(base_attack_damage);
    }
}

void Creature::get_damage(unsigned int damage) {
    this->set_has_changed(true);
    damage -= armor > damage ? damage : armor;
    curr_hp -= damage > curr_hp ? curr_hp : damage;
}

void Creature::restore_health(unsigned int d_hp) {
    curr_hp += d_hp;
    this->set_has_changed(true);
    if (curr_hp > max_hp)
    {
        curr_hp = max_hp;
    }
}


