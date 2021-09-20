//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_EXITCELL_H
#define OOP_GAME_EXITCELL_H
#include "Cell.h"

class ExitCell : public Cell {
public:
    ExitCell(unsigned int x, unsigned int y);
    virtual void interact();
};


#endif //OOP_GAME_EXITCELL_H
