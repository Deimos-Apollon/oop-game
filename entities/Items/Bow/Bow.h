//
// Created by Deimos on 20.10.2021.
//

#ifndef OOP_GAME_BOW_H
#define OOP_GAME_BOW_H
#include "../Item/Item.h"

class Bow : public Item {
    unsigned int damage;
    void attack(Creature *creature) override;
public:
    Bow(unsigned int range=5, unsigned int damage=10, unsigned int usages=50);
    bool is_damaging() const override;
    void interact(Creature *creature) override;
    nlohmann::json get_json_repr() const override;
};


#endif //OOP_GAME_BOW_H
