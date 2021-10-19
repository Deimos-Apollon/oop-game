//
// Created by Deimos on 12.10.2021.
//

#include "ApproachStrategy.h"


void ApproachStrategy::step(FieldInterface *field, Enemy *enemy, Player *player) {
    if (enemy->try_do_step()) {
        pair<int, int> coords = field->calculate_differ_in_distance_with_player(enemy);
        if (abs(coords.first) <= enemy->get_attack_range() && abs(coords.second) <= enemy->get_attack_range()) {
            enemy->attack(player, coords.first, coords.second);
        } else {
            auto drow = coords.first > 0 ? -1 : 1;
            drow = coords.first != 0 ? drow : 0;
            auto dcol = coords.second > 0 ? -1 : 1;
            dcol = coords.second != 0 ? dcol : 0;
            field->move_enemy(enemy, drow, dcol);
        }
    }
}

