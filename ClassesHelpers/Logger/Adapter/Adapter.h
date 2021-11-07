//
// Created by deimos on 03.11.2021.
//

#ifndef OOP_GAME_ADAPTER_H
#define OOP_GAME_ADAPTER_H


#include <string>
#include "../../../entities/Creatures/Player/Player.h"
#include "../../../entities/Creatures/Enemies/Enemy/Enemy.h"

using namespace std;
class Adapter {
public:
    string player_info(Player& player);
    string enemy_info(Enemy& enemy);
    string item_info(Item& item);
};


#endif //OOP_GAME_ADAPTER_H
