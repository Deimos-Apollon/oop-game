//
// Created by deimos on 19.09.2021.
//
#include "Game/Game/Game.h"
#include "Game/Game/Game.cpp"

int main() {

    // TODO (попробовать хранить стратегию в enemy)
    Game<AllEnemiesDeadRules, AllEnemiesDeadRules> game;
    game.start();
}