//
// Created by deimos on 19.09.2021.
//

#include "Cell.h"

Cell::Cell(unsigned int x, unsigned int y, bool is_vacant): x(x), y(y), is_vacant(is_vacant)
{

}

Cell* Cell::clone() {
    Cell* tmp = new Cell(this->x, this->y);
    return tmp;
}
