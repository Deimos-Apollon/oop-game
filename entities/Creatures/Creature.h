//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_CREATURE_H

#include "../Entity.h"
#include "../../field/Cells/Wall.h"
#include "../../field/Field.h"

#define OOP_GAME_CREATURE_H


class Creature : public Entity {
protected:
    Field* field = nullptr;
    unsigned int hp = 0;
    int armor = 0;
    unsigned int base_attack_damage = 1;
    unsigned int attack_range = 1;
    Creature();
    explicit Creature(Field* field, Cell* cell, unsigned int hp_p = 0, int armor_p = 0, unsigned int base_attack_damage = 1);
    explicit Creature(unsigned int hp_p = 0, int armor_p = 0, unsigned int base_attack_damage = 1);
public:
    ~Creature() override = default;
    virtual void move(Cell* move_to);
    virtual void move(unsigned int drow, unsigned int dcol);
    unsigned int get_attack_range() const { return attack_range; };
    unsigned int get_hp() const { return hp; }
    virtual void attack(Creature* other_creature);
    virtual void get_damage(unsigned int damage);
};


#endif //OOP_GAME_CREATURE_H
