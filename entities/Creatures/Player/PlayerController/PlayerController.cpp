//
// Created by Deimos on 12.10.2021.
//

#include <iostream>
#include "PlayerController.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void PlayerController::check_for_input() {
    if (_kbhit())
    {
        auto code = _getch();
        switch (code)
        {
            // left
            case KEY_LEFT:
                field->move_player(player, 0, -1);
                break;
            // right
            case KEY_RIGHT:
                field->move_player(player, 0, 1);
                break;
            // up
            case KEY_UP:
                field->move_player(player, -1, 0);
                break;
            // down
            case KEY_DOWN:
                field->move_player(player, 1, 0);
                break;
            // spacebar
            case 32:
                field->player_attack_nearest_enemy();
                break;
            case 's':
                player->change_using_item();
                std::cout << "changed using item";
                break;
        }
    }
}
