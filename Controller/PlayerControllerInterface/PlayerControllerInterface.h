//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_PLAYERCONTROLLER_H
#include "../../field/FieldInterface/FieldInterface.h"
#include "../../Game/CommandExecutor.h"
#include "../../Game/GameSerialising/GameSaverLoaderJSON/GameSaverLoaderJSON.h"

#define OOP_GAME_PLAYERCONTROLLER_H

class PlayerControllerInterface
{
protected:
    CommandExecutor command_executor;
    GameSaverLoaderJSON* gameSaverLoaderJson = nullptr;
public:
    virtual void proceed() = 0;
    void set_field(FieldInterface* &field, bool& need_to_load_level)
            { command_executor.set_field(field, need_to_load_level); }
    void set_player(Player* &player) { command_executor.set_player(player); }
    void setGameSaverLoaderJSON(GameSaverLoaderJSON* new_game_saver) {gameSaverLoaderJson = new_game_saver; }
};

#endif //OOP_GAME_PLAYERCONTROLLER_H
