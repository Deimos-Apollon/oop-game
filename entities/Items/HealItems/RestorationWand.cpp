//
// Created by Deimos on 18.10.2021.
//

#include "RestorationWand.h"

void RestorationWand::interact(Creature *creature) {
    if (usages != 0) {
        this->heal(creature);
        --usages;
        this->set_has_changed(true);
    }
}

void RestorationWand::heal(Creature *creature) {
    creature->restore_health(heal_power);
}

RestorationWand::RestorationWand(unsigned int heal_power, unsigned int usages) : Item(heal_power, usages) {

}

nlohmann::json RestorationWand::get_json_repr() const {
    nlohmann::json item_view = {
            {"type", "RestorationWand"},
            {"range", range},
            {"heal_power", heal_power},
            {"usages", usages},
    };
    return item_view;
}
