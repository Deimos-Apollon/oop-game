//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_PLAYER_H
#define OOP_GAME_PLAYER_H


#include "../Creature/Creature.h"
#include "../../Items/Item/Item.h"
#include "../../Items/MeleeDamageItems/Axe/Axe.h"
#include <vector>

using namespace std;
class Player : public Creature {
    vector <Item*> items = {};
    Item* current_item = nullptr;
    bool using_item = false;
public:
    Player(unsigned int hp_p = 0, int armor_p = 0, unsigned int base_attack_damage = 0);
    ~Player() override;

    void use_item(Creature* creature,  int drow,  int dcol);
    void change_using_item();
    void add_item(Item* new_item);

    bool is_item_healing() { return !current_item->is_damaging(); }
    void attack(Creature *other_creature, int drow,  int dcol) override;
};


#endif //OOP_GAME_PLAYER_H
