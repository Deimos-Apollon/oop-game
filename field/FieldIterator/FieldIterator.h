//
// Created by deimos on 24.09.2021.
//

#ifndef OOP_GAME_FIELDITERATOR_H
#include "../Field/Field.h"
#define OOP_GAME_FIELDITERATOR_H

class FieldIterator{
    Field& field;
    unsigned int curr_row = 0;
    unsigned int curr_col = 0;
public:
    explicit FieldIterator(Field& field) : field(field) {};
    const Cell *const next();
    const Cell *const operator++();
    unsigned int get_cols() { return field.get_cols(); }
    bool has_More();
    void refresh();
};


#endif //OOP_GAME_FIELDITERATOR_H
