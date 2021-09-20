//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_FIELD_H
#define OOP_GAME_FIELD_H

#include "Cells/Cell.h"
#include "Cells/ExitCell.h"
#include "Cells/EnterCell.h"

class Field {
    const unsigned int rows;
    const unsigned int cols;
    Cell*** cells;
public:
    Field(unsigned int rows, unsigned int cols);
};


#endif //OOP_GAME_FIELD_H
