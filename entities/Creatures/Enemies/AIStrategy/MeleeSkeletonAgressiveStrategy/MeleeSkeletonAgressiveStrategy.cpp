//
// Created by Deimos on 19.10.2021.
//

#include "MeleeSkeletonAgressiveStrategy.h"

void MeleeSkeletonAgressiveStrategy::step(FieldInterface *field, Enemy *enemy, Player *player) {
    if (can_do_spec_move())
    {
        if (enemy->try_do_step()) {
            do_spec_move(field, enemy, player);
            spec_move_cooldown = SPEC_MOVE_COOLDOWN;
        }
    }else
    {
        ApproachStrategy::step(field, enemy, player);
    }
}

void MeleeSkeletonAgressiveStrategy::do_spec_move(FieldInterface *field, Enemy *enemy, Player *player) {
    auto coords = field->calculate_differ_in_distance_with_player(enemy);
    if (abs(coords.first) <= spec_move_range && abs(coords.second) <= spec_move_range)
    {
        player->get_damage(SPEC_MOVE_DAMAGE);
    }
}

bool MeleeSkeletonAgressiveStrategy::can_do_spec_move() {
    if (spec_move_cooldown == 0)
    {
        return true;
    }
    else
    {
        --spec_move_cooldown;
        return false;
    }
}
