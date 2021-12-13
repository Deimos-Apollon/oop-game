//
// Created by deimos on 01.12.2021.
//

#ifndef OOP_GAME_PLAYERCONTROLLERCLI_H
#define OOP_GAME_PLAYERCONTROLLERCLI_H


#include <map>
#include <utility>
#include "../PlayerControllerInterface.h"
#include "../../CommandsCodes/CommandsCodes.h"

class PlayerControllerCLI : public PlayerControllerInterface {
    map<char, Commands> keys_to_commands;
public:
    PlayerControllerCLI() = default;
    explicit PlayerControllerCLI(const map<Commands, char>& commands_to_keys) {
        for (auto pair: commands_to_keys)
            keys_to_commands[pair.second] = pair.first;
    }
    void proceed() override;
};


#endif //OOP_GAME_PLAYERCONTROLLERCLI_H
