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
    explicit FieldIterator(const Field& field) : field(const_cast<Field &>(field)) {};
    const Cell *const next();
    const Cell *const operator++();
    unsigned int get_cols() { return field.get_cols(); }
    bool has_More();
    void refresh();
    void change_field(Field& new_field){
        field = new_field;
        this->refresh();
    }
};


#endif //OOP_GAME_FIELDITERATOR_H
