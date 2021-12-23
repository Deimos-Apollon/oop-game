//
// Created by Deimos on 13.10.2021.
//

#ifndef OOP_GAME_MELEESKELETON_H

#include "../../Enemy/Enemy.h"

#define OOP_GAME_MELEESKELETON_H


class MeleeSkeleton : public Enemy {
public:
    explicit MeleeSkeleton(unsigned int hp_max = 15, unsigned int hp_curr = 15,
                           int armor = 0, unsigned int damage = 5, unsigned int attack_range = 1);
    nlohmann::json get_json_repr() const override;
};


#endif //OOP_GAME_MELEESKELETON_H
