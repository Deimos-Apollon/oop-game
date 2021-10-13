//
// Created by Deimos on 09.10.2021.
//

#ifndef OOP_GAME_ITEM_H
#define OOP_GAME_ITEM_H


#include "../Entity.h"
#include "../Creatures/Creature.h"

class Player;

class Item : public Entity {
    unsigned int usages = 0;
protected:
    virtual void attack(Creature* creature) {};
    virtual void heal(Creature* creature) {};
public:
    Item() : Entity() {};
    explicit Item(Cell* cell): Entity(cell) {};
    virtual void interact(Creature* creature) {};
};


#endif //OOP_GAME_ITEM_H
