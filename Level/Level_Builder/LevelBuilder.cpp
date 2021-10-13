//
// Created by Deimos on 13.10.2021.
//

#include "LevelBuilder.h"

void LevelBuilder::create_field(unsigned int rows, unsigned int cols, unsigned int walls_percentage) {
    field = new Field(rows, cols, walls_percentage);
}
