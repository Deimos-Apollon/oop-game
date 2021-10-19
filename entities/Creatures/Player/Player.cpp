//
// Created by deimos on 20.09.2021.
//

#include "Player.h"

Player::Player(unsigned int hp_p, int armor_p, unsigned int base_attack_damage) :
        Creature(hp_p, armor_p, base_attack_damage){

}


void Player::add_item(Item* new_item) {
    items.push_back(new_item);
    if (current_item == nullptr)
    {
        current_item = new_item;
    }
}

void Player::use_item(Creature *creature, int drow, int dcol) {
    if (abs(drow) <= current_item->get_range() && abs(dcol) <= current_item->get_range())
        current_item->interact(creature);
}

void Player::attack(Creature *other_creature,  int drow,  int dcol) {
    if (using_item) {
        if (current_item->is_damaging())
            use_item(other_creature, drow, dcol);
        else
            use_item(this, 0, 0);
    }
    else {
        if (abs(drow) <= attack_range && abs(dcol) <= attack_range) {
            other_creature->get_damage(base_attack_damage);
        }
    }
}

void Player::change_using_item() {
    if (current_item != nullptr) {
        this->using_item = !this->using_item;
    }
}

