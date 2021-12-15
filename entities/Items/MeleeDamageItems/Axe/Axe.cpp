//
// Created by Deimos on 13.10.2021.
//

#include "Axe.h"

Axe::Axe(unsigned int range, unsigned int damage, unsigned int usages) : MeleeDamageItem(range, damage, usages){

}

nlohmann::json Axe::get_json_repr() const {
    nlohmann::json item_view = {
            {"type", "Bow"},
            {"range", range},
            {"damage", damage},
            {"usages", usages},
    };
    return item_view;
}
