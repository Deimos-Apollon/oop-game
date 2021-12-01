//
// Created by deimos on 01.12.2021.
//

#include <iostream>
#include "CLI_GameMenu.h"


void CLI_GameMenu::print() {
    std::cout << "=============Game menu==============\n"
                 "1) Start game\n"
                 "2) Settings\n"
                 "3) Exit\n";
}

void CLI_GameMenu::print_curr_settings(SettingsCLI &settings) {
    std::cout << "=============Game Settings==============\n";
    for (auto pair: settings.get_curr_settings())
    {
        std::cout << setting_name[pair.first] << " : " << pair.second << '\n';
    }
}
