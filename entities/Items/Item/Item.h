//
// Created by Deimos on 09.10.2021.
//

#ifndef OOP_GAME_ITEM_H
#define OOP_GAME_ITEM_H


#include "../../Creatures/Creature/Creature.h"

class Item : public Entity{
    virtual void attack(Creature* creature) {};
    virtual void heal(Creature* creature) {};
protected:
    unsigned int range = 0;
    unsigned int usages = 0;
public:
    Item() = default;
    explicit Item(unsigned int range, unsigned int usages) : range(range), usages(usages) {};
    virtual void interact(Creature* creature) {};
    virtual bool is_damaging() { return false; };
    unsigned int get_range() { return range; }
};


#endif //OOP_GAME_ITEM_H
