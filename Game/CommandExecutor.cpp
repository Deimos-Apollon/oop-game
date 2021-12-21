//
// Created by deimos on 13.12.2021.
//

#include "CommandExecutor.h"

CommandExecutor::CommandExecutor(Player *player, FieldInterface *field) : player(player), field(field) {
    method_to_call = {
            {MOVE_RIGHT, [this, &field] {field->move_player(0, 1);} },
            {MOVE_LEFT, [this, &field] {field->move_player(0, -1);} },
            {MOVE_DOWN, [this, &field] {field->move_player(1, 0);} },
            {MOVE_UP, [this, &field] {field->move_player( -1, 0);} },
            {ATTACK, [this, &field] {field->player_attack_nearest_enemy();} },
            {CHANGE_USING_ITEM, [this, &player] { player->change_using_item();} },
            {SWITCH_ITEM, [this, &player] {player->switch_to_next_item();} },
            {SAVE_GAME, [this, field] {gameSaverLoaderJson.save_game(field);}},
    };
}

void CommandExecutor::execute_command(Commands command) {
    if (command != DO_NOTHING)
    {
        method_to_call[command]();
    }
}

void CommandExecutor::set_field(FieldInterface *&new_field, bool& need_to_load_level) {
    field = new_field;
    method_to_call[MOVE_RIGHT] = [this] {field->move_player(0, 1);};
    method_to_call[MOVE_LEFT] = [this] {field->move_player(0, -1);};
    method_to_call[MOVE_DOWN] = [this] {field->move_player(1, 0);};
    method_to_call[MOVE_UP] = [this] {field->move_player(-1, 0);};
    method_to_call[ATTACK] = [this] {field->player_attack_nearest_enemy();};
    method_to_call[SAVE_GAME] = [this] {gameSaverLoaderJson.save_game(field);};
    method_to_call[LOAD_GAME] = [this, &need_to_load_level, &new_field]
            {need_to_load_level = gameSaverLoaderJson.load_game(new_field, player);};
}

void CommandExecutor::set_player(Player* &new_player) {
    player = new_player;
    method_to_call[CHANGE_USING_ITEM] = [this] { player->change_using_item();};
    method_to_call[SWITCH_ITEM] = [this] {player->switch_to_next_item();};
}
