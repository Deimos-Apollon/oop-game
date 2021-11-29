//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_PLAYERCONTROLLER_H
#include "../../../../field/FieldInterface/FieldInterface.h"

#define OOP_GAME_PLAYERCONTROLLER_H

class PlayerController
{
    FieldInterface* field;
    Player* player;
public:
    explicit PlayerController(Player* player, FieldInterface* field=nullptr) : field(field), player(player) {};
    void set_field(FieldInterface* new_field) { field = new_field; }
    void check_for_input();
};

#endif //OOP_GAME_PLAYERCONTROLLER_H
