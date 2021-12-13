//
// Created by deimos on 01.12.2021.
//

#include <iostream>
#include "PlayerControllerCLI.h"
#include <map>

void hi()
{

}
void PlayerControllerCLI::proceed() {
    char got_code;
    std::cin >> got_code;

    command_executor.execute_command(keys_to_commands[got_code]);
}
