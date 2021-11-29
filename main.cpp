//
// Created by deimos on 19.09.2021.
//
#include "Game/Game/Game.h"
#include "Game/Game/Game.cpp"


int main() {

    // TODO исправить на size_t, создать Level, который будет хранить правила и поле, и передавать туда тапл классов игры
    Game<PickedItem<Bow>, AllEnemiesDeadRules<double>> game((PickedItem<Bow>()),  (AllEnemiesDeadRules<double>(10)));
    game.start();
}