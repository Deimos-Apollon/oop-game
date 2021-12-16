//
// Created by deimos on 01.12.2021.
//

#include <iostream>
#include "CLI_GameMenuView.h"


void CLI_GameMenuView::print() {
    std::cout << "=============Game menu==============\n"
                 "1) Start game\n"
                 "2) Load game\n"
                 "3) Settings\n"
                 "4) Exit\n";
}

void CLI_GameMenuView::print_curr_settings(SettingsCLI &settings) {
    std::cout << "=============Game Settings==============\n";

    for (auto pair: settings.get_curr_settings())
    {
        std::cout << "#" << pair.first << " " << setting_name[pair.first] << " : " << pair.second << '\n';
    }
}
