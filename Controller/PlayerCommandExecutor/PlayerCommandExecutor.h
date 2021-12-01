//
// Created by deimos on 01.12.2021.
//

#ifndef OOP_GAME_PLAYERCOMMANDEXECUTOR_H
#define OOP_GAME_PLAYERCOMMANDEXECUTOR_H


#include <iostream>
#include "../PlayerControllerInterface/PlayerControllerInterface.h"
#include "../../field/Field/Field.h"
#include "/home/deimos/CLionProjects/oop-game/Controller/CommandsCodes/CommandsCodes.h"
#include <typeinfo>

template<class T>
class PlayerCommandExecutor {
    PlayerControllerInterface* player_controller = nullptr;
    FieldInterface* field = nullptr;
    Player* player = nullptr;
public:
    PlayerCommandExecutor() = delete;
    PlayerCommandExecutor(Settings)
    explicit PlayerCommandExecutor(Player* player);
    void set_field(FieldInterface* new_field);
    void set_player(Player* new_player);
    void proceed();
    ~PlayerCommandExecutor();
};

template<class T>
void PlayerCommandExecutor<T>::proceed() {
    auto got_code = player_controller->check_for_input();

    // switch is not working with non const
    if (got_code == MOVE_UP)
    {
        field->move_player( -1, 0);
    }
    else if (got_code == MOVE_DOWN)
    {
        field->move_player(1, 0);
    }
    else if (got_code == MOVE_LEFT)
    {
        field->move_player(0, -1);
    }
    else if (got_code == MOVE_RIGHT)
    {
        field->move_player(0, 1);
    }
    else if (got_code == ATTACK)
    {
        field->player_attack_nearest_enemy();
    }
    else if (got_code == CHANGE_USING_ITEM)
    {
        player->change_using_item();
    }
    else if (got_code == SWITCH_ITEM)
    {
        player->switch_to_next_item();
    }

}

template<class T>
PlayerCommandExecutor<T>::PlayerCommandExecutor() : player_controller(new T){

}

template<class T>
PlayerCommandExecutor<T>::~PlayerCommandExecutor() {
    delete player_controller;
    player_controller = new T();
}

template<class T>
PlayerCommandExecutor<T>::PlayerCommandExecutor(Player *player) : player_controller(new T) {

}

template<class T>
void PlayerCommandExecutor<T>::set_field(FieldInterface *new_field) {
    field = new_field;
}

template<class T>
void PlayerCommandExecutor<T>::set_player(Player *new_player) {
    player = new_player;
}



#endif //OOP_GAME_PLAYERCOMMANDEXECUTOR_H
