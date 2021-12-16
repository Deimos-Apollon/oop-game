//
// Created by deimos on 01.12.2021.
//

#ifndef OOP_GAME_SETTINGSCLI_H
#define OOP_GAME_SETTINGSCLI_H


#include "../../../Controller/CommandsCodes/CommandsCodes.h"
#include "../SettingsInterface.h"
#include <map>
using namespace  std;

class SettingsCLI : public SettingsInterface {
    map<Commands, char> commands_to_keys;
public:
    SettingsCLI();
    void change_key(Commands command, char new_value);
    // removed map<char, Commands> get_key_bounds();
    map<Commands, char> get_curr_settings() { return commands_to_keys; };
    // TODO refactor map<char, Commands>, it is not necessary
    // TODO delete redundant methods and classes
};


#endif //OOP_GAME_SETTINGSCLI_H
