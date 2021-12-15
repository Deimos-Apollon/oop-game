//
// Created by deimos on 13.12.2021.
//

#ifndef OOP_GAME_COMMANDEXECUTOR_H
#define OOP_GAME_COMMANDEXECUTOR_H


#include <map>
#include <functional>
#include "../entities/Creatures/Player/Player.h"
#include "../field/FieldInterface/FieldInterface.h"
#include "../Controller/CommandsCodes/CommandsCodes.h"
#include "GameSerialising/GameSaverLoaderJSON/GameSaverLoaderJSON.h"

class CommandExecutor {
    Player* player = nullptr;
    FieldInterface* field = nullptr;
    GameSaverLoaderJSON gameSaverLoaderJson;
    std::map <Commands, std::function<void()>> method_to_call;
public:
    explicit CommandExecutor(Player* player = nullptr, FieldInterface* field = nullptr);
    void execute_command(Commands command);
    void set_field(FieldInterface* new_field);
    void set_player(Player* new_player);
};


#endif //OOP_GAME_COMMANDEXECUTOR_H
