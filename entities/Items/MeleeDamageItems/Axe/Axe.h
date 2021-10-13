//
// Created by Deimos on 13.10.2021.
//

#ifndef OOP_GAME_AXE_H

#include "../MeleeDamageItem.h"

#define OOP_GAME_AXE_H


class Axe : public MeleeDamageItem{
public:
    Axe(unsigned int range, unsigned int damage);
    Axe(Cell* cell, unsigned int range, unsigned int damage);
};


#endif //OOP_GAME_AXE_H
