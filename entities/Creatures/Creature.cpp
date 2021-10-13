//
// Created by deimos on 20.09.2021.
//

#include "Creature.h"


Creature::Creature(Field* field, Cell* cell, unsigned int hp_p, int armor_p, unsigned int base_attack_damage):
    field(field), Entity(cell), hp(hp_p), armor(armor_p), base_attack_damage(base_attack_damage) {

}

Creature::Creature(unsigned int hp_p, int armor_p, unsigned int base_attack_damage) :
        hp(hp_p), armor(armor_p), base_attack_damage(base_attack_damage){

}

Creature::Creature() : Entity() {

}



void Creature::attack(Creature *other_creature) {
    other_creature->get_damage(base_attack_damage);
}

void Creature::get_damage(unsigned int damage) {
    damage -= armor > damage ? damage : armor;
    hp -= damage > hp ? hp : damage;
}

void Creature::move(Cell *move_to) {
    if (typeid(*move_to) != typeid(Wall) && move_to->get_entity() == nullptr) {
        auto tmp = this->cell;
        this->cell = move_to;
        tmp->set_entity(nullptr);
        this->cell->set_entity(this);
    }
}

void Creature::move(unsigned int drow, unsigned int dcol) {
    auto row = this->cell->get_row() + drow;
    auto col = this->cell->get_col() + dcol;
    if ((row > 1 && row < field->get_rows()) && (col > 1 && col < field->get_cols())) {
        auto move_to = field->get_cell_non_const(row, col);
        if (typeid(*move_to) != typeid(Wall) && move_to->get_entity() == nullptr) {
            auto tmp = this->cell;
            this->cell = move_to;
            tmp->set_entity(nullptr);
            this->cell->set_entity(this);
        }
    }
}


