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
        this->set_has_changed(true);
    }
}

void Player::use_item(Creature *creature, int drow, int dcol) {
    if (using_item && abs(drow) <= current_item->get_range() && abs(dcol) <= current_item->get_range())
        current_item->interact(creature);
}

void Player::attack(Creature *other_creature,  int drow,  int dcol) {
    if (using_item) {
        if (current_item->is_damaging())
            use_item(other_creature, drow, dcol);
        else {
            use_item(this, 0, 0);
            this->set_has_changed(true);
        }
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
        this->set_has_changed(true);
    }
}

Player::~Player() {
    for (auto item: items)
    {
        delete item;
    }
    items = {};
}

void Player::switch_to_next_item() {
    if (using_item) {
        ++current_item_index;
        if (current_item_index == items.size())
            current_item_index = 0;
        current_item = items[current_item_index];
        this->set_has_changed(true);
    }
}

nlohmann::json Player::get_json_repr() const {
    nlohmann::json player_view = {
            {"type", "Player"},
            {"max_hp", max_hp},
            {"curr_hp", curr_hp},
            {"armor", armor},
            {"base_attack_damage", base_attack_damage},
            {"attack_range", attack_range},
            {"using_item", using_item},
            {"items", {}}
    };
    for (auto item: items)
    {
        player_view["items"].push_back(item->get_json_repr());
    }
    return player_view;
}

