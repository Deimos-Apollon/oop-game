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

public:
};


#endif //OOP_GAME_ADAPTER_H
