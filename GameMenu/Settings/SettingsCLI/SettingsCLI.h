//
// Created by deimos on 01.12.2021.
//

#ifndef OOP_GAME_SETTINGSCLI_H
#define OOP_GAME_SETTINGSCLI_H


#include "../../../Controller/CommandsCodes/CommandsCodes.h"
#include "../SettingsInterface.h"
#include <map>
using namespace  std;

class SettingsCLI : public SettingsInterface{
    map<Commands, char> keys_to_commands;
public:
    SettingsCLI();
    void change_key(Commands command, char new_value);
    map<char, Commands> get_key_bounds();
    map<Commands, char> get_curr_settings() { return keys_to_commands; };
};


#endif //OOP_GAME_SETTINGSCLI_H
