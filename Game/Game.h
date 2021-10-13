//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_GAME_H

#include "../field/Field.h"
#include "../Level/LevelInterface/LevelInterface.h"
#include "../Level/Level.h"
#include "GameInterface.h"

#define OOP_GAME_GAME_H


class Game : GameInterface{                         // Ask how to create multiple levels (mind using LevelBuilder)
    Player* player = nullptr;
    LevelInterface** levels = nullptr;
    unsigned int levels_num = 0;
protected:
    void proceed() override;
    void finish() override;
public:
    Game() {};
    Game(Player* player, LevelInterface** levels, unsigned int levels_num);
    void start() override;
};


#endif //OOP_GAME_GAME_H
