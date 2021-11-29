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
    {
        char code;
        std::cin >> code;
        switch (code)
        {
            // left
            case 'a':
                field->move_player(0, -1);
                break;
            // right
            case 'd':
                field->move_player(0, 1);
                break;
            // up
            case 'w':
                field->move_player( -1, 0);
                break;
            // down
            case 's':
                field->move_player(1, 0);
                break;
            // spacebar
            case 'q':
                field->player_attack_nearest_enemy();
                break;
            case 'i':
                player->change_using_item();
                std::cout << "using_item";
                break;
            case 'n':
                player->switch_to_next_item();
                std::cout << "NEW item";
                break;
            default:
                break;
        }
    }
}
