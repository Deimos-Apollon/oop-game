//
// Created by Deimos on 19.10.2021.
//

#ifndef OOP_GAME_MELEESKELETONAGRESSIVESTRATEGY_H
#define OOP_GAME_MELEESKELETONAGRESSIVESTRATEGY_H

#include "../ApproachStrategy/ApproachStrategy.h"
#define SPEC_MOVE_COOLDOWN 20
#define SPEC_MOVE_RANGE 3
#define SPEC_MOVE_DAMAGE 10

class MeleeSkeletonAgressiveStrategy : public ApproachStrategy {
    unsigned int spec_move_cooldown = SPEC_MOVE_COOLDOWN;
    const unsigned int spec_move_range = SPEC_MOVE_RANGE;
    void do_spec_move(FieldInterface *field, Enemy *enemy, Player *player);
    bool can_do_spec_move();
public:
    void step(FieldInterface *field, Enemy *enemy, Player *player) override;
};


#endif //OOP_GAME_MELEESKELETONAGRESSIVESTRATEGY_H
