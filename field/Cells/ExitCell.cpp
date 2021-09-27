//
// Created by deimos on 19.09.2021.
//

#include "ExitCell.h"

Cell *ExitCell::clone() {
    Cell* tmp = new ExitCell(this->x, this->y);
    return tmp;
}
