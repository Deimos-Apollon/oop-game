//
// Created by Deimos on 19.10.2021.
//

#include "MageHealer.h"

MageHealer::MageHealer(unsigned int hp_max, unsigned int hp_curr, int armor, unsigned int damage, unsigned int attack_range) :
        Enemy(hp_max, hp_curr, armor, damage, attack_range) {

}

nlohmann::json MageHealer::get_json_repr() const {
    nlohmann::json enemy_view = {
            {"type", "MageHealer"},
            {"max_hp", max_hp},
            {"curr_hp", curr_hp},
            {"armor", armor},
            {"base_attack_damage", base_attack_damage},
            {"attack_range", attack_range},
    };
    return enemy_view;
}
