//
// Created by Deimos on 12.10.2021.
//

#include "ApproachStrategy.h"


void ApproachStrategy::step(Enemy *enemy, Player *player) {
    auto enemy_row = enemy->get_row();
    auto enemy_col = enemy->get_col();

    auto player_row = player->get_row();
    auto player_col = player->get_col();

    if ( (abs(int(enemy_row - player_row)) <=  enemy->get_attack_range())
            && (abs(int(enemy_col - player_col)) <= enemy->get_attack_range()) )
    {
        enemy->attack(player);
    }
    else
    {
        auto d_row = enemy_row > player_row ? -1 : 1;
        d_row = enemy_row == player_row ? 0 : d_row;
        auto d_col = enemy_col > player_col ? -1 : 1;
        d_col = enemy_col == player_col ? 0 : d_col;
        enemy->move(d_row, d_col);
    }
}
