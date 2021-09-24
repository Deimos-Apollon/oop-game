//
// Created by deimos on 24.09.2021.
//

#include "FieldIterator.h"

Cell *const  FieldIterator::next() {
    auto ret_row = curr_row;
    auto ret_col = curr_col;
    if (curr_row == field.rows)         // TODO effective checks
    {
        curr_row = 0;
        curr_col = 0;
        return nullptr;
    }
    if (curr_col == field.cols - 1) {
        curr_col = 0;
        ++curr_row;
    } else ++curr_col;
    Cell *const ret = field.cells[ret_row][ret_col];
    return ret;
}

bool FieldIterator::has_More() {
    if (curr_row == field.rows)
        return false;
    return true;
}

