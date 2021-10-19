//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_PLAYERCONTROLLER_H
#include "../../../../field/FieldInterface/FieldInterface.h"
#include <conio.h>
#define OOP_GAME_PLAYERCONTROLLER_H

class PlayerController
{
    FieldInterface* field;
    Player* player;
public:
    PlayerController(FieldInterface* field, Player* player) : field(field), player(player) {};
    void check_for_input();
};

#endif //OOP_GAME_PLAYERCONTROLLER_H
