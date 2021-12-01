//
// Created by deimos on 01.12.2021.
//

#include "SettingsCLI.h"

SettingsCLI::SettingsCLI() {
    keys_to_commands = {
        {' ', DO_NOTHING},
        {'a', MOVE_LEFT},
        {'d', MOVE_RIGHT},
        {'w', MOVE_UP},
        {'s', MOVE_DOWN},
        {'q', ATTACK},
        {'u', CHANGE_USING_ITEM},
        {'n', SWITCH_ITEM},
    };
}
