//
// Created by deimos on 19.09.2021.
//
#include "Game/Game/Game.h"
#include "Game/Game/Game.cpp"


int main() {

    // TODO (попробовать хранить стратегию в enemy)
    Game<PickedItem<Bow>, AllEnemiesDeadRules<double>> game((PickedItem<Bow>()),  (AllEnemiesDeadRules<double>(3.2)));
    game.start();
}