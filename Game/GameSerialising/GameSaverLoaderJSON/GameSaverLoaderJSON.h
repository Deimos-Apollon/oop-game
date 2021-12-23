//
// Created by deimos on 14.12.2021.
//

#ifndef OOP_GAME_GAMESAVERLOADERJSON_H
#define OOP_GAME_GAMESAVERLOADERJSON_H

#include "../GameSaverLoaderInterface/GameSaverLoaderInterface.h"
#include "/home/deimos/CLionProjects/oop-game/external_libraries/json.hpp"
#include "JSONSaveableInterface/JSONSaveableInterface.h"
#include "GameObjectsJsonCreator.h"

class GameSaverLoaderJSON {
    using json = nlohmann::json;
    GameObjectsJsonCreator gameObjectsJsonCreator;
public:
    // TODO разобраться с полями, которвые выводятся и загружаются, разбить функции загрузки чтобы было меньше
    bool load_game(FieldInterface* &field, Player* &player, const std::string& filename = "game_save.json");
    void save_game(FieldInterface *field, const std::string& filename = "game_save.json");
};

#endif //OOP_GAME_GAMESAVERLOADERJSON_H
