//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_FIELD_H
#define OOP_GAME_FIELD_H

#include "Cells/Cell.h"
#include "Cells/ExitCell.h"
#include "Cells/EnterCell.h"
#include "random"

unsigned int get_random_int(unsigned int max_int_not_included);

class Field {
protected:
    const unsigned int rows;
    const unsigned int cols;
    Cell*** cells;
public:
    Field(unsigned int rows, unsigned int cols);

};


#endif //OOP_GAME_FIELD_H
