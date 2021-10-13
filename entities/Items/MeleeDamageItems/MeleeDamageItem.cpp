//
// Created by Deimos on 13.10.2021.
//

#include "MeleeDamageItem.h"

MeleeDamageItem::MeleeDamageItem(unsigned int range, unsigned int damage) :
        Item(), range(range), damage(damage){

}

MeleeDamageItem::MeleeDamageItem(Cell *cell, unsigned int range, unsigned int damage) :
        Item(cell), range(range), damage(damage){

}

void MeleeDamageItem::interact(Creature *creature) {
    this->attack(creature);
}

void MeleeDamageItem::attack(Creature *creature) {
    creature->get_damage(damage);
}
