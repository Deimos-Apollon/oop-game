//
// Created by Deimos on 18.10.2021.
//

#include "RestorationWand.h"

void RestorationWand::interact(Creature *creature) {
    if (usages != 0) {
        this->heal(creature);
        --usages;
    }
}

void RestorationWand::heal(Creature *creature) {
    creature->restore_health(heal_power);
}

RestorationWand::RestorationWand(unsigned int heal_power, unsigned int usages) : Item(heal_power, usages) {

}
