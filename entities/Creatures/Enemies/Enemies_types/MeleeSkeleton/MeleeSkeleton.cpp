//
// Created by Deimos on 13.10.2021.
//

#include "MeleeSkeleton.h"


MeleeSkeleton::MeleeSkeleton(unsigned int hp, int armor, unsigned int damage, unsigned int attack_range) :
        Enemy(hp, armor, damage, attack_range)
{

}

nlohmann::json MeleeSkeleton::get_json_repr() const{
    nlohmann::json enemy_view = {
            {"type", "MeleeSkeleton"},
            {"max_hp", max_hp},
            {"curr_hp", curr_hp},
            {"armor", armor},
            {"base_attack_damage", base_attack_damage},
            {"attack_range", attack_range},
    };
    return enemy_view;
}

