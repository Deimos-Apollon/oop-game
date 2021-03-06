//
// Created by Deimos on 20.10.2021.
//

#include "Bow.h"

void Bow::attack(Creature *creature) {
    creature->get_damage(damage);
}

bool Bow::is_damaging() const {
    return true;
}

void Bow::interact(Creature *creature) {
    if (usages != 0) {
        --usages;
        this->set_has_changed(true);
        this->attack(creature);
    }
}

Bow::Bow(unsigned int range, unsigned int damage, unsigned int usages) :
    Item(range, usages), damage(damage)
{

}

nlohmann::json Bow::get_json_repr() const {
    nlohmann::json item_view = {
            {"type", "Bow"},
            {"range", range},
            {"damage", damage},
            {"usages", usages},
    };
    return item_view;
}

