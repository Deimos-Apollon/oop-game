//
// Created by Deimos on 13.10.2021.
//

#ifndef OOP_GAME_MELEEDAMAGEITEM_H
#include "../Item/Item.h"
#define OOP_GAME_MELEEDAMAGEITEM_H


class MeleeDamageItem : public Item {
    unsigned int damage;
    void attack(Creature *creature) override;
public:
    MeleeDamageItem(unsigned int range, unsigned int damage, unsigned int usages);
    void interact(Creature *creature) override;
    bool is_damaging() const  override { return true; }
};


#endif //OOP_GAME_MELEEDAMAGEITEM_H
