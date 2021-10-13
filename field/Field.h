//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_FIELD_H

#include "Cells/Cell.h"
#include "Cells/ExitCell.h"
#include "Cells/EnterCell.h"
#include "Cells/Wall.h"
#include <random>

#define OOP_GAME_FIELD_H


unsigned int get_random_int(unsigned int min_int, unsigned int max_int);

class Field {
private:
    void create_path(unsigned x_ent, unsigned y_ent,
                     unsigned x_exit, unsigned y_exit);
protected:
    unsigned int rows = 0;
    unsigned int cols = 0;
    unsigned int walls_percentage = 30; // 0 to 90
    Cell*** cells = nullptr;
    Cell* enter_cell = nullptr;
    Cell* exit_cell = nullptr;
public:
    Field(unsigned int rows, unsigned int cols, unsigned  int walls_percentage=50); // TODO delete Player
    Field(Field& other);
    Field& operator=(Field& other);
    Field(Field&& other) noexcept ;
    Field& operator=(Field&& other) noexcept ;
    ~Field();
    unsigned int get_rows() const { return rows; }
    unsigned int get_cols() const { return cols; }
    const Cell* const get_cell(unsigned int row, unsigned int col);

    Cell* get_cell_non_const(unsigned int row, unsigned int col) { return cells[row][col];};
    Cell* get_enter_cell() { return enter_cell; }
    Cell* get_exit_cell() { return exit_cell; }
};


#endif //OOP_GAME_FIELD_H
