//
// Created by Deimos on 13.10.2021.
//

#include "MeleeSkeleton.h"

MeleeSkeleton::MeleeSkeleton() : Enemy(15,0,5) {

}

MeleeSkeleton::MeleeSkeleton(Field *field, Cell *cell) : Enemy(field, cell, 15, 0, 5){

}
