//
// Created by Deimos on 18.10.2021.
//

#ifndef OOP_GAME_RESTORATIONWAND_H
#define OOP_GAME_RESTORATIONWAND_H

#define HEAL_POWER 5

#include "../Item/Item.h"

class RestorationWand : public Item {
    unsigned int heal_power = HEAL_POWER;
    void heal(Creature *creature) override;
public:
    RestorationWand(unsigned int heal_power = HEAL_POWER, unsigned int usages = 5);
    void interact(Creature *creature) override;
    bool is_damaging() const override { return false; }
};


#endif //OOP_GAME_RESTORATIONWAND_H
