//
// Created by deimos on 14.12.2021.
//

#ifndef OOP_GAME_GAMESAVERLOADERJSON_H
#define OOP_GAME_GAMESAVERLOADERJSON_H

#include "../GameSaverLoaderInterface/GameSaverLoaderInterface.h"
#include "/home/deimos/CLionProjects/oop-game/external_libraries/json.hpp"
#include "JSONSaveableInterface/JSONSaveableInterface.h"

class GameSaverLoaderJSON {
    using json = nlohmann::json;
public:
    void load_game(const std::string& filename, const std::vector<FieldInterface *> &field);
    void save_game(const std::string& filename, JSONSaveableInterface *save_objects);
};

#endif //OOP_GAME_GAMESAVERLOADERJSON_H
