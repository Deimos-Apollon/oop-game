//
// Created by Deimos on 13.10.2021.
//

#ifndef OOP_GAME_MELEEDAMAGEITEM_H
#include "../Item.h"
#define OOP_GAME_MELEEDAMAGEITEM_H


class MeleeDamageItem : public Item {
    unsigned int range;
    unsigned int damage;
    void attack(Creature *creature) override;
public:
    MeleeDamageItem(unsigned int range, unsigned int damage);
    MeleeDamageItem(Cell* cell, unsigned int range, unsigned int damage);
    void interact(Creature *creature) override;
};


#endif //OOP_GAME_MELEEDAMAGEITEM_H
