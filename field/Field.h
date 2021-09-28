//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_FIELD_H
#define OOP_GAME_FIELD_H

#include "Cells/Cell.h"
#include "Cells/ExitCell.h"
#include "Cells/EnterCell.h"
#include "Cells/Wall.h"
#include "random"

unsigned int get_random_int(unsigned int min_int, unsigned int max_int);

class FieldIterator;        // declare so we can use is in this file

class Field {
private:
    void create_path(unsigned x_ent, unsigned y_ent,
                     unsigned x_exit, unsigned y_exit);
protected:
    unsigned int rows = 0;
    unsigned int cols = 0;
    unsigned int walls_percentage = 50; // 0 to 90
    Cell*** cells = nullptr;
public:
    Field(unsigned int rows, unsigned int cols, unsigned  int walls_percentage=50);
    Field(Field& other);
    Field& operator=(Field& other);
    Field(Field&& other) noexcept ;
    Field& operator=(Field&& other) noexcept ;
    ~Field();
    unsigned int get_rows() const { return rows; }
    unsigned int get_cols() const { return cols; }
    const Cell* const get_cell(unsigned int x, unsigned int y);
};


#endif //OOP_GAME_FIELD_H
