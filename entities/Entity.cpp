//
// Created by deimos on 20.09.2021.
//

#include "Entity.h"
#include "../field/Cells/Cell.h"

Cell* cell;

Entity::~Entity() {
    cell->set_entity(nullptr);
}
