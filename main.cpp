//
// Created by deimos on 19.09.2021.
//
#include "Game/Game.h"
#include "CLI_Interface/field_interface/FieldView.h"
#include "field/FieldIterator.h"
#include "entities/Creatures/Player/Player.h"
#include "CLI_Interface/level_interface/LevelView.h"
#include "Level/Level.h"


int main() {
//    unsigned int rows, cols;
//    std::cout << "Enter rows and cols: \n";
//    std::cin >> rows >> cols;
//    auto* player = new Player;
//    Field field0(rows, cols);
//    FieldIterator fi0(field0);
//    LevelInterface** l = new LevelInterface*[1];
//    l[0] = new Level(player, &field0);
//    player->set_cell(field0.get_enter_cell());
//    field0.get_enter_cell()->set_entity(player);

    Game game;
    game.start();
}