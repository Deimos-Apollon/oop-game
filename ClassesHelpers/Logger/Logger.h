//
// Created by deimos on 03.11.2021.
//

#ifndef OOP_GAME_LOGGER_H

#include <iostream>
#include "Adapter/Adapter.h"

#define OOP_GAME_LOGGER_H

class Logger {
    Adapter adapter;
public:
    void print(Player& player) { std::cout << adapter.player_info(player) << '\n'; }
};


#endif //OOP_GAME_LOGGER_H
