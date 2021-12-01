//
// Created by deimos on 01.12.2021.
//

#include <iostream>
#include "PlayerControllerCLI.h"


void PlayerControllerCLI::proceed() {
    char got_code;
    std::cin >> got_code;
    if (keys_to_commands[got_code] == MOVE_UP)
    {
        field->move_player( -1, 0);
    }
    else if (keys_to_commands[got_code] == MOVE_DOWN)
    {
        field->move_player(1, 0);
    }
    else if (keys_to_commands[got_code] == MOVE_LEFT)
    {
        field->move_player(0, -1);
    }
    else if (keys_to_commands[got_code] == MOVE_RIGHT)
    {
        field->move_player(0, 1);
    }
    else if (keys_to_commands[got_code] == ATTACK)
    {
        field->player_attack_nearest_enemy();
    }
    else if (keys_to_commands[got_code] == CHANGE_USING_ITEM)
    {
        player->change_using_item();
    }
    else if (keys_to_commands[got_code] == SWITCH_ITEM)
    {
        player->switch_to_next_item();
    }
}
