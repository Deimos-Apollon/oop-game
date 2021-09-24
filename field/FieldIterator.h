//
// Created by deimos on 24.09.2021.
//

#ifndef OOP_GAME_FIELDITERATOR_H
#define OOP_GAME_FIELDITERATOR_H

#include "Field.h"

class FieldIterator{
    Field& field;
    unsigned curr_row = 0;
    unsigned curr_col = 0;
public:
    explicit FieldIterator(Field& field) : field(field) {};
    Cell *const next();
    bool has_More();
};


#endif //OOP_GAME_FIELDITERATOR_H
