//
// Created by deimos on 19.09.2021.
//

#include "Field.h"

Field::Field(unsigned int rows, unsigned int cols): rows(rows), cols(cols){
    cells = new Cell**[rows];

    if (rows == 1 and cols == 1)
    {
        std::cout << "Error";
    }
    else {
        // init cells
        for (unsigned int i = 0; i < rows; ++i) {
            cells[i] = new Cell *[cols];
            for (unsigned int j = 0; j < cols; ++j) {
                cells[i][j] = new Cell(i, j);
            }
        }

        // init enter and exit cells coordinates
        unsigned int x_ent = 0, y_ent = 0, x_exit = 0, y_exit = 0;
        while (abs(x_ent - x_exit) < (rows + 1) / 2 and
               abs(y_ent - y_exit) < (cols + 1) / 2) {
            x_ent = get_random_int(rows);
            y_ent = get_random_int(cols);
            x_exit = get_random_int(rows);
            y_exit = get_random_int(cols);
        }

        // add exit and enter cells in cells
        delete cells[x_ent][y_ent];
        cells[x_ent][y_ent] = new EnterCell(x_ent, y_ent);
        delete cells[x_exit][y_exit];
        cells[x_exit][y_exit] = new ExitCell(x_exit, y_exit);

        // TODO delete this
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                cells[i][j]->interact();
            }
            std::cout << '\n';
        }
    }
}

unsigned int get_random_int(unsigned int max_int_not_included)
{
    return rand() % max_int_not_included;
}