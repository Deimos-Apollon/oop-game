//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_PLAYER_H
#define OOP_GAME_PLAYER_H


#include "../Creature.h"
#include "../../Items/Item.h"
#include "../../Items/MeleeDamageItems/Axe/Axe.h"

using namespace std;
class Player : public Creature {

    vector <Item*> items = {};
    Item* current_item = nullptr;
public:
    Player(Field *field = nullptr, Cell *cell = nullptr, unsigned int hp_p = 0, int armor_p = 0, unsigned int base_attack_damage = 0);
    Player(unsigned int hp_p, int armor_p, unsigned int base_attack_damage);
    ~Player() override = default;
    void use_item(Creature *creature) { current_item->interact(creature); };
    void set_field(Field *field);
    void move(Cell *move_to) override;
    void move(unsigned int drow, unsigned int dcol) override;
    void add_item(Item* new_item);
};


#endif //OOP_GAME_PLAYER_H
