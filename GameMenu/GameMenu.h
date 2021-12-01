//
// Created by deimos on 01.12.2021.
//

#ifndef OOP_GAME_GAMEMENU_H
#define OOP_GAME_GAMEMENU_H


#include "/home/deimos/CLionProjects/oop-game/Game/Game/Game.h"
#include "../Game/Game/Game.cpp"
#include "../Controller/PlayerControllerInterface/PlayerControllerCLI/PlayerControllerCLI.h"
#include "../Controller/CommandsCodes/CommandsCodes.h"
#include "/home/deimos/CLionProjects/oop-game/Game/GameRules/NumberOfEnemiesDeadRules/NumberOfEnemiesDeadRules.h"
#include "/home/deimos/CLionProjects/oop-game/Game/GameRules/NumberOfEnemiesDeadRules/NumberOfEnemiesDeadRules.cpp"
#include "Settings/SettingsCLI/SettingsCLI.h"
#include "../CLI_Interface/CLI_GameMenu/CLI_GameMenu.h"

class GameMenu {
    Game<PickedItem<Bow>, NumberOfEnemiesDeadRules<10>> game{PickedItem<Bow>(),  NumberOfEnemiesDeadRules<10>()};
    PlayerControllerCLI player_controller;
    SettingsCLI settings_CLI;
    enum window_showing { MAIN_MENU, SETTING };
    window_showing window = MAIN_MENU;

    CLI_GameMenu game_menu_view;
private:
    void params_init();
    void switch_to_next();
public:
    GameMenu(){};
    void run();
};


#endif //OOP_GAME_GAMEMENU_H
