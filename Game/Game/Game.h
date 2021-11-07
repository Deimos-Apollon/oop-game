//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_GAME_H

#include "../../field/Field/Field.h"
#include "../GameIntreface/GameInterface.h"

#include "../../field/FieldBuilder/FieldBuilder.h"
#include "../../ClassesHelpers/Logger/Logger.h"

#define OOP_GAME_GAME_H


class Game : GameInterface{                         // Ask how to create multiple levels (mind using LevelBuilder)
    Player* player = nullptr;
    FieldInterface** fields = nullptr;
    unsigned int fields_num = 0;

    Logger logger;
protected:
    void proceed() override;
    void finish() override;
public:
    Game() = default;
    ~Game();
    Game(Player* player, FieldInterface** fields, unsigned int fields_num);
    void start() override;
};


#endif //OOP_GAME_GAME_H
