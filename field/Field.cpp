//
// Created by deimos on 19.09.2021.
//

#include "Field.h"

Field::Field(unsigned int rows, unsigned int cols): rows(rows), cols(cols){
    Cell*** tmp_cells = new Cell**[rows];

    for (unsigned int i = 0; i < rows; ++i)
    {
        tmp_cells[i] = new Cell*[cols];
    }
    tmp_cells[0][0] = new EnterCell(0, 0);
    tmp_cells[rows-1][cols-1] = new ExitCell(rows-1, cols-1);

    // init first row cells
    if (rows != 1) {
        for (unsigned int j = 1; j < cols; ++j) {
            tmp_cells[0][j] = new Cell(0, j);
        }
    }
    // init other cells
    for (unsigned int i = 1; i < rows - 1; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            tmp_cells[i][j] = new Cell(i, j);
        }
    }
    // init last row cells
    if (rows != 1) {
        for (unsigned int j = 0; j < cols - 1; ++j) {
            tmp_cells[rows - 1][j] = new Cell(rows - 1, j);
        }
    }
    // rows = 1 is another case
    if (rows == 1)
    {
        for (unsigned int j = 1; j < cols - 1; ++j) {
            tmp_cells[0][j] = new Cell(0, j);
        }
    }
    this->cells = tmp_cells;
}
