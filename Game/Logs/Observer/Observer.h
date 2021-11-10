//
// Created by Deimos on 07.11.2021.
//

#ifndef OOP_GAME_OBSERVER_H
#define OOP_GAME_OBSERVER_H


#include <vector>
#include <map>
#include <string>
#include "../../../entities/Entity/Entity.h"
#include "../../../entities/Creatures/Player/Player.h"
#include "../../../entities/Creatures/Enemies/Enemy/Enemy.h"

class Observer {
    std::map <const Entity*, std::vector <unsigned int> > objects_cache;

    std::map <size_t, string> phrases_player;
    std::map <size_t, string> phrases_enemy;
    std::map <size_t, string> phrases_item;

    void add_player(const Player* player);
    void add_item(const Item* item);
    void add_enemy(const Enemy* enemy);

    std::string check_player(const Player* player);
    std::string check_item(const Item* item);
    std::string check_enemy(const Enemy* enemy);
public:
    Observer();
    void add_object(const Entity* entity);

    std::string check_object(const Entity* entity);
};


#endif //OOP_GAME_OBSERVER_H
