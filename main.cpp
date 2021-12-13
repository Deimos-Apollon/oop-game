//
// Created by deimos on 19.09.2021.
//


#include "GameMenu/GameMenuCLI.h"

int main() {

    Game<PickedItem<Bow>, NumberOfEnemiesDeadRules<10>> game{PickedItem<Bow>(),  NumberOfEnemiesDeadRules<10>(10)};
    GameMenuCLI gameMenu(game);
    gameMenu.run();
}