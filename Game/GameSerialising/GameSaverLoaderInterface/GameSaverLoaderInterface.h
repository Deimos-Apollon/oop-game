//
// Created by deimos on 14.12.2021.
//

#ifndef OOP_GAME_GAMESAVERLOADERINTERFACE_H
#define OOP_GAME_GAMESAVERLOADERINTERFACE_H


#include "../../../field/FieldInterface/FieldInterface.h"
#include <string>

class GameSaverLoaderInterface {
public:
    virtual void save_game(std::string filename, const std::vector<FieldInterface*> &field, const Player& player) = 0;
    virtual void load_game(std::string filename, std::vector<FieldInterface*> &field, Player& player ) = 0;
};


#endif //OOP_GAME_GAMESAVERLOADERINTERFACE_H
