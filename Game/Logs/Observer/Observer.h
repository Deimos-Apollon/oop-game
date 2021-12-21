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
#include "../Adapter/Adapter.h"

class Observer {
    std::map <const Entity*, std::vector <unsigned int> > objects_cache;
    Adapter adapter;

    void add_player(const Player* player);
    void add_item(const Item* item);
    void add_enemy(const Enemy* enemy);

    std::string check_player(const Player* player);
    std::string check_item(const Item* item);
    std::string check_enemy(const Enemy* enemy);

    std::string check_object(const Entity* entity);

public:
    Observer();
    void add_object(const Entity* entity);
    void remove_object(const Entity* entity);
    void remove_all();
    std::string check_objects();
};


#endif //OOP_GAME_OBSERVER_H
