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

    std::vector<FieldInterface*> fields = {};
    size_t current_field = 0;
    size_t field_prev_number = 0;
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
    void reload();
    void start();
};


#endif //OOP_GAME_GAME_H
