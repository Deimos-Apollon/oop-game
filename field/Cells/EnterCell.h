//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_ENTERCELL_H
#define OOP_GAME_ENTERCELL_H


#include "Cell.h"

class EnterCell : public Cell{
public:
    EnterCell(unsigned int x, unsigned int y);
    virtual void interact();
};


#endif //OOP_GAME_ENTERCELL_H
