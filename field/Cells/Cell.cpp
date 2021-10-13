//
// Created by deimos on 19.09.2021.
//

#include "Cell.h"

Cell::Cell(unsigned int row, unsigned int col, bool vacant): row(row), col(col), vacant(vacant)
{

}

Cell* Cell::clone() {
    Cell* tmp = new Cell(this->row, this->col);
    return tmp;
}

unsigned int Cell::getID() const{
    return 0;
}
