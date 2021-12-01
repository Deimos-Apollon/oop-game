//
// Created by deimos on 01.12.2021.
//

#ifndef OOP_GAME_CLI_GAMEMENUVIEW_H
#define OOP_GAME_CLI_GAMEMENUVIEW_H


#include "../CLI_Printable/CLI_Printable.h"
#include "../../GameMenu/Settings/SettingsCLI/SettingsCLI.h"

class CLI_GameMenuView : CLI_Printable{
    std::map<Commands, string> setting_name =
            {
                    {DO_NOTHING, "Skip your turn"},
                    {MOVE_LEFT, "Move left"},
                    {MOVE_RIGHT, "Move rigth"},
                    {MOVE_UP, "Move up"},
                    {MOVE_DOWN, "Move down"},
                    {ATTACK, "Attack"},
                    {CHANGE_USING_ITEM, "Change using item or not"},
                    {SWITCH_ITEM, "Switch to next item in inventory"},
            };
public:
    void print() override;
    void print_curr_settings(SettingsCLI& settings);
};


#endif //OOP_GAME_CLI_GAMEMENUVIEW_H
