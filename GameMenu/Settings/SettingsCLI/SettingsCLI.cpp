//
// Created by deimos on 01.12.2021.
//

#include "SettingsCLI.h"

SettingsCLI::SettingsCLI() {
    keys_to_commands = {
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
    keys_to_commands[command] = new_value;
}

map<char, Commands> SettingsCLI::get_key_bounds() {
    map<char, Commands> ret = {};
    for (auto key: keys_to_commands)
    {
        ret[key.second] = key.first;
    }
    return ret;
}
