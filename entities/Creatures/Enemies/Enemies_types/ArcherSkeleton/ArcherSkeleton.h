//
// Created by Deimos on 19.10.2021.
//

#ifndef OOP_GAME_ARCHERSKELETON_H
#define OOP_GAME_ARCHERSKELETON_H

#include "../../Enemy/Enemy.h"

class ArcherSkeleton : public Enemy {
public:
    explicit ArcherSkeleton(unsigned int hp = 10, int armor = 0, unsigned int damage = 3, unsigned int attack_range = 5);
    nlohmann::json get_json_repr() const override;
};


#endif //OOP_GAME_ARCHERSKELETON_H
