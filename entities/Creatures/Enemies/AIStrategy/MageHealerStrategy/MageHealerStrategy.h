//
// Created by Deimos on 19.10.2021.
//

#ifndef OOP_GAME_MAGEHEALERSTRATEGY_H
#define OOP_GAME_MAGEHEALERSTRATEGY_H

#define HEAL_COOLDOWN 20
#define HEAL_POWER 5

#include "../ApproachStrategy/ApproachStrategy.h"

class MageHealerStrategy : public ApproachStrategy {
    unsigned int heal_cooldown = HEAL_COOLDOWN;
    bool try_do_heal();
    void heal(FieldInterface *field);
public:
    void step(FieldInterface *field, Enemy *enemy, Player *player) override;
};


#endif //OOP_GAME_MAGEHEALERSTRATEGY_H
