//
// Created by deimos on 01.12.2021.
//

#ifndef OOP_GAME_GAMEMENU_H
#define OOP_GAME_GAMEMENU_H


#include "/home/deimos/CLionProjects/oop-game/Game/Game/Game.h"
#include "../Game/Game/Game.cpp"
#include "../Controller/PlayerCommandExecutor/PlayerCommandExecutor.h"
#include "../Controller/PlayerControllerInterface/PlayerControllerCLI/PlayerControllerCLI.h"
#include "../Controller/CommandsCodes/CommandsCodes.h"
#include "/home/deimos/CLionProjects/oop-game/Game/GameRules/NumberOfEnemiesDeadRules/NumberOfEnemiesDeadRules.h"
#include "/home/deimos/CLionProjects/oop-game/Game/GameRules/NumberOfEnemiesDeadRules/NumberOfEnemiesDeadRules.cpp"

class GameMenu {
    Game<PickedItem<Bow>, NumberOfEnemiesDeadRules<10>> game{PickedItem<Bow>(),  NumberOfEnemiesDeadRules<10>()};

public:
    GameMenu();
};


#endif //OOP_GAME_GAMEMENU_H
