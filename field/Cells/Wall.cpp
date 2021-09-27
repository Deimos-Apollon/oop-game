//
// Created by deimos on 20.09.2021.
//

#include "Wall.h"

Cell *Wall::clone() {
    Cell* tmp = new Wall(this->x, this->y);
    return tmp;
}
