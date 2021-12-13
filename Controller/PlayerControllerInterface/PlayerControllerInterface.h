//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_PLAYERCONTROLLER_H
#include "../../field/FieldInterface/FieldInterface.h"
#include "../../Game/CommandExecutor.h"

#define OOP_GAME_PLAYERCONTROLLER_H

class PlayerControllerInterface
{
protected:
    CommandExecutor command_executor;
public:
    virtual void proceed() = 0;
    void set_field(FieldInterface* field) { command_executor.set_field(field); }
    void set_player(Player* player) { command_executor.set_player(player); }
};

#endif //OOP_GAME_PLAYERCONTROLLER_H
