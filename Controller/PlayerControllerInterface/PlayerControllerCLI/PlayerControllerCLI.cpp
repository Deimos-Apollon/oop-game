//
// Created by deimos on 01.12.2021.
//

#include <iostream>
#include "PlayerControllerCLI.h"

unsigned int PlayerControllerCLI::check_for_input() {
    char code;
    std::cin >> code;
    auto elem = keys_to_commands.find(code);
    if (elem != keys_to_commands.end())
    {
        return keys_to_commands[code];
    }
    else
    {
        return DO_NOTHING;
    }
}


