//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_PLAYERCONTROLLER_H
#include "../../field/FieldInterface/FieldInterface.h"

#define OOP_GAME_PLAYERCONTROLLER_H

class PlayerControllerInterface
{
protected:
    Player* player = nullptr;
    FieldInterface* field = nullptr;
public:
    virtual void proceed() = 0;
    void set_field(FieldInterface* field) { this->field = field;}
    void set_player(Player* player) { this->player = player; }
};

#endif //OOP_GAME_PLAYERCONTROLLER_H
