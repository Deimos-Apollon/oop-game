//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_GAME_H

#include "../../field/Field/Field.h"


#include "../../field/FieldBuilder/FieldBuilder.h"
#include "../GameRules/AllEnemiesDeadRules.h"
#include "../../CLI_Interface/CLI_Field/FieldView.h"

#define OOP_GAME_GAME_H


template <class ...Rules>
class Game{
    Player* player = nullptr;
    FieldInterface** fields = nullptr;
    unsigned int fields_num = 0;

    std::tuple <Rules...> levels_rules = {Rules{}...};

    Logger logger;
protected:
    void proceed();
    void finish();
public:
    Game() = default;
    ~Game();
    Game(Player* player, FieldInterface** fields, unsigned int fields_num);
    void start();
};


#endif //OOP_GAME_GAME_H
