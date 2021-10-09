//
// Created by deimos on 19.09.2021.
//

#include "EnterCell.h"

Cell *EnterCell::clone() {
    Cell* tmp = new EnterCell(this->x, this->y);
    return tmp;
}

unsigned int EnterCell::getID() const{
    return 1;
}
