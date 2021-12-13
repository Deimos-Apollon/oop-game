//
// Created by deimos on 01.12.2021.
//

#include "SettingsCLI.h"

SettingsCLI::SettingsCLI() {
    commands_to_keys = {
        {DO_NOTHING, ' '},
        {MOVE_LEFT, 'a'},
        {MOVE_RIGHT, 'd'},
        {MOVE_UP, 'w'},
        {MOVE_DOWN, 's'},
        {ATTACK, 'q'},
        {CHANGE_USING_ITEM, 'u'},
        {SWITCH_ITEM, 'n'},
    };
}

void SettingsCLI::change_key(Commands command, char new_value) {
    bool not_exist = true;
    for (auto command_to_key: commands_to_keys)
    {
        if (command_to_key.second == new_value)
        {
            not_exist = false;
        }
    }
    if (not_exist) {
        commands_to_keys[command] = new_value;
    }
}

