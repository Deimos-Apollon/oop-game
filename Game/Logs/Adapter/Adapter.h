//
// Created by deimos on 03.11.2021.
//

#ifndef OOP_GAME_ADAPTER_H
#define OOP_GAME_ADAPTER_H

#include <ostream>
#include <string>

#include "../../../entities/Creatures/Player/Player.h"
#include "../../../entities/Creatures/Enemies/Enemy/Enemy.h"

std::ostream& operator<<(ostream& out, const Player& player);
std::ostream& operator<<(std::ostream& out, const Item& item);
std::ostream& operator<<(std::ostream& out, const Enemy& enemy);
std::ostream& operator<<(std::ostream& out, const Entity* entity);

using namespace std;

class Adapter {
    std::vector <string> phrases_player;
    std::vector <string> phrases_enemy;
    std::vector <string> phrases_item;
public:
    Adapter();
    string two_differs_to_player_info(size_t parameter_index, unsigned int old_value, unsigned int new_value);
    string two_differs_to_item_info(size_t parameter_index, unsigned int old_value, unsigned int new_value);
    string two_differs_to_enemy_info(size_t parameter_index, unsigned int old_value, unsigned int new_value);
};


#endif //OOP_GAME_ADAPTER_H
