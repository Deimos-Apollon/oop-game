//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_CELL_H
#include <iostream>
#include "../../entities/Entity.h"
#define OOP_GAME_CELL_H


class Cell {
protected:
    unsigned int x;
    unsigned int y;
    bool is_vacant;
    Entity* entity;
public:
    Cell(unsigned int x, unsigned int y, bool is_vacant=true);
    virtual ~Cell() = default;
    virtual Cell* clone();
};


#endif //OOP_GAME_CELL_H
