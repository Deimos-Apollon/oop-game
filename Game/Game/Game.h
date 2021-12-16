//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_GAME_H

#include "../../field/Field/Field.h"


#include "../../field/FieldBuilder/FieldBuilder.h"
#include "../../CLI_Interface/CLI_Field/FieldView.h"


#include "../GameRules/NumberOfEnemiesDeadRules/NumberOfEnemiesDeadRules.h"
#include "../GameRules/PickedItem/PickedItem.h"
#include "../../Controller/PlayerControllerInterface/PlayerControllerInterface.h"
#include "../../Controller/PlayerControllerInterface/PlayerControllerCLI/PlayerControllerCLI.h"

#include "../GameSerialising/GameSaverLoaderJSON/GameSaverLoaderJSON.h"

#define OOP_GAME_GAME_H


template <class ...Rules>
class Game{
    Player* player = nullptr;
    PlayerControllerInterface* player_controller = nullptr;
    bool need_to_load_new = false;

    std::vector<FieldInterface*> fields = {};
    size_t current_field = 0;
    unsigned int fields_num = 0;

    std::tuple <Rules...> levels_rules;

    Logger logger;
protected:
    void proceed();
    void finish();

    void levels_init();
public:
    Game() = default;
    explicit Game(Rules... args): levels_rules(args...){};
    ~Game();
    Game(Player* player, std::vector<FieldInterface*> fields, unsigned int fields_num);
    Game(Player* player, FieldInterface* field_to_load, size_t field_num);

    void setPlayerController(PlayerControllerInterface* pc) { player_controller = pc; };

    bool get_need_to_load_new() {return need_to_load_new;}
    FieldInterface* get_field_to_load() {if (need_to_load_new) return fields[current_field];
        else return nullptr;}
    Player* get_player_to_load() {if (need_to_load_new) return player; else return nullptr;};

    void start();
};


#endif //OOP_GAME_GAME_H
