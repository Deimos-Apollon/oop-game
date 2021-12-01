//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_PLAYERCONTROLLER_H
#include "../../field/FieldInterface/FieldInterface.h"

#define OOP_GAME_PLAYERCONTROLLER_H

class PlayerControllerInterface
{
public:
    virtual unsigned int check_for_input() = 0;
};

#endif //OOP_GAME_PLAYERCONTROLLER_H
