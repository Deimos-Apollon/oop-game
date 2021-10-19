//
// Created by Deimos on 13.10.2021.
//

#include "MeleeDamageItem.h"

MeleeDamageItem::MeleeDamageItem(unsigned int range, unsigned int damage, unsigned int usages) :
        Item(range, usages), damage(damage){

}


void MeleeDamageItem::interact(Creature *creature) {
    this->attack(creature);
}

void MeleeDamageItem::attack(Creature *creature) {
    creature->get_damage(damage);
}
