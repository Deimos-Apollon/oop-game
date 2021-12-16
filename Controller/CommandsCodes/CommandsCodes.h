//
// Created by deimos on 01.12.2021.
//

#ifndef OOP_GAME_COMMANDSCODES_H
#define OOP_GAME_COMMANDSCODES_H

#include <cstddef>

enum Commands {
    DO_NOTHING,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_UP,
    MOVE_DOWN,
    ATTACK,
    CHANGE_USING_ITEM,
    SWITCH_ITEM,
    SAVE_GAME,
    LOAD_GAME
};

const size_t Commands_length = 8;

#endif //OOP_GAME_COMMANDSCODES_H
