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
    explicit PlayerControllerCLI(map<char, Commands> keys_to_commands): keys_to_commands(std::move(keys_to_commands)) {
    }

    void proceed() override;
};


#endif //OOP_GAME_PLAYERCONTROLLERCLI_H
