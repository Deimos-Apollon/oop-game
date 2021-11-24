//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_GAME_H

#include "../../field/Field/Field.h"


#include "../../field/FieldBuilder/FieldBuilder.h"
#include "../../CLI_Interface/CLI_Field/FieldView.h"

#include "../GameRules/AllEnemiesDeadRules/AllEnemiesDeadRules.h"
#include "../GameRules/PickedItem/PickedItem.h"


#define OOP_GAME_GAME_H


template <class ...Rules>
class Game{
    Player* player = nullptr;
    PlayerController* player_controller = nullptr;
    FieldInterface** fields = nullptr;
    unsigned int fields_num = 0;

    std::tuple <Rules...> levels_rules;

    Logger logger;
protected:
    void proceed();
    void finish();
public:
    Game() = default;
    explicit Game(Rules... args): levels_rules(args...){};
    ~Game();
    Game(Player* player, FieldInterface** fields, unsigned int fields_num);
    void start();
};


#endif //OOP_GAME_GAME_H
