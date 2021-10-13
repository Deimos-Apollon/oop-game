//
// Created by deimos on 20.09.2021.
//

#include "Player.h"

Player::Player(Field* field, Cell *cell, unsigned int hp_p, int armor_p, unsigned int base_attack_damage) :
        Creature(field, cell, hp_p, armor_p, base_attack_damage) {
}

void Player::set_field(Field* field) {
    this->field = field;
}

Player::Player(unsigned int hp_p, int armor_p, unsigned int base_attack_damage) :
        Creature(hp_p, armor_p, base_attack_damage){

}

void Player::move(Cell *move_to) {
    if (move_to->is_vacant()) {
        if (move_to->get_entity() == nullptr) {
            auto tmp = this->cell;
            this->cell = move_to;
            tmp->set_entity(nullptr);
            this->cell->set_entity(this);
        } else if (move_to->if_has_item())
        {
            auto tmp = this->cell;
            this->cell = move_to;
            tmp->set_entity(nullptr);

            Item* new_item = (Item *) this->cell->get_entity();
            this->add_item(new_item);

            this->cell->set_entity(this);
        }
    }
}

void Player::move(unsigned int drow, unsigned int dcol) {
    auto row = this->cell->get_row() + drow;
    auto col = this->cell->get_col() + dcol;
    if ((row > 1 && row < field->get_rows()) && (col > 1 && col < field->get_cols())) {
        auto move_to = field->get_cell_non_const(row, col);
        if (move_to->is_vacant()) {
            if (move_to->get_entity() == nullptr) {
                auto tmp = this->cell;
                this->cell = move_to;
                tmp->set_entity(nullptr);
                this->cell->set_entity(this);
            } else if (move_to->if_has_item()) {
                auto tmp = this->cell;
                this->cell = move_to;
                tmp->set_entity(nullptr);
                this->cell->set_entity(this);
            }
        }
    }
}

void Player::add_item(Item* new_item) {
    items.push_back(new_item);
    if (current_item == nullptr)
    {
        current_item = new_item;
    }
}
