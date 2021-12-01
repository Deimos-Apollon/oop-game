//
// Created by deimos on 01.12.2021.
//

#ifndef OOP_GAME_SETTINGSCLI_H
#define OOP_GAME_SETTINGSCLI_H


#include "../../../Controller/CommandsCodes/CommandsCodes.h"
#include <map>
using namespace  std;

class SettingsCLI {
    map<char, Commands> keys_to_commands;
public:
    SettingsCLI();
};


#endif //OOP_GAME_SETTINGSCLI_H
