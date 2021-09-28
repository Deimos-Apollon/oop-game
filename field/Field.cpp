//
// Created by deimos on 19.09.2021.
//

#include "Field.h"
#include <random>


Field::Field(unsigned int rows, unsigned int cols, unsigned int walls_percentage): rows(rows + 2), cols(cols + 2){
    auto rows_with_walls = rows + 2;
    auto cols_with_walls = cols + 2;
    cells = new Cell**[rows_with_walls];

    if (rows == 1 and cols == 1)
    {
        for (unsigned int i = 0; i < rows_with_walls; ++i) {
            cells[i] = new Cell *[cols_with_walls];
            for (unsigned int j = 0; j < cols_with_walls; ++j) {
                cells[i][j] = new Wall(i, j);
            }
        }
        delete cells[1][1];
        cells[1][1] = new EnterCell(1,1);
    }
    else if (rows < 1 or cols < 1)
    {
        std::cout << "Error, incorrect rows or cols";
    }
    else {
        // declare cells
        for (unsigned int i = 0; i < rows_with_walls; ++i) {
            cells[i] = new Cell *[cols_with_walls];
        }
        // init cells
        for (unsigned int i = 1; i < rows_with_walls - 1; ++i) {
            for (unsigned int j = 1; j < cols_with_walls - 1; ++j) {
                if (get_random_int(1, 100) > walls_percentage)
                    cells[i][j] = new Cell(i, j);
                else
                    cells[i][j] = new Wall(i, j);
            }
        }

        // init enter and exit cells coordinates
        unsigned int scalar = (cols != 1 and rows != 1) ? 2 : ((cols == 1) ? rows_with_walls : cols_with_walls);
        unsigned int x_ent = 1, y_ent = 1, x_exit = 1, y_exit = 1;
        while (abs(x_ent - x_exit) < (rows_with_walls) / scalar or
               abs(y_ent - y_exit) < (cols_with_walls) / scalar) {
            x_ent = get_random_int(1, rows_with_walls - 2);
            y_ent = get_random_int(1, cols_with_walls - 2);
            x_exit = get_random_int(1, rows_with_walls - 2);
            y_exit = get_random_int(1, cols_with_walls - 2);
        }

        // add exit and enter cells in cells
        delete cells[x_ent][y_ent];
        cells[x_ent][y_ent] = new EnterCell(x_ent, y_ent);
        delete cells[x_exit][y_exit];
        cells[x_exit][y_exit] = new ExitCell(x_exit, y_exit);

        // init edge walls
        // up
        for (unsigned int j = 0; j < cols_with_walls; ++j)
        {
            cells[0][j] = new Wall(0, j);
        }
        //down
        for (unsigned int j = 0; j < cols_with_walls; ++j)
        {
            cells[rows_with_walls - 1][j] = new Wall(rows_with_walls - 1, j);
        }
        //left
        for (unsigned int i = 1; i < rows_with_walls - 1; ++i)
        {
            cells[i][0] = new Wall(i, 0);
        }
        // right
        for (unsigned int i = 1; i < rows_with_walls - 1; ++i)
        {
            cells[i][cols_with_walls - 1] = new Wall(i, cols_with_walls - 1);
        }

        // add one truly existing path
        this->create_path(x_ent, y_ent, x_exit, y_exit);
    }
}


Field::Field(Field &other) : rows(other.rows), cols(other.cols), walls_percentage(other.walls_percentage){
    // TODO delete this
    std::cout << "!!!copy constr\n";
    cells = new Cell**[rows];
    for (unsigned int i = 0; i < rows; ++i)
    {
        cells[i] = new Cell *[cols];
        for (unsigned int j = 0; j < cols; ++j)
        {
            cells[i][j] = other.cells[i][j]->clone();
        }
    }
}

void Field::create_path(unsigned int x_ent, unsigned int y_ent, unsigned int x_exit, unsigned int y_exit) {
    auto tmp_x = x_ent, tmp_y = y_ent;
    while(true){
        if (get_random_int(1, 2) == 1){
            tmp_x += x_exit > tmp_x ? 1 : -1;       // if exit is left from enter, move left, otherwise right
            if (tmp_x == 0) ++tmp_x;
        } else {
            tmp_y += y_exit > tmp_y ? 1 : -1;       // if exit is above enter, move up, else move down
            if (tmp_y == 0) ++tmp_y;
        }
        if (tmp_x == x_exit and tmp_y == y_exit)
        {
            break;
        }
        if (typeid(*cells[tmp_x][tmp_y]) == typeid(Wall))
        {
            delete cells[tmp_x][tmp_y];
            cells[tmp_x][tmp_y] = new Cell(tmp_x, tmp_y);
        }
    }
}

Field::~Field() {
    //std::cout << "destructor\n";
    for (unsigned int i = 0; i < rows; ++i)
    {
        for (unsigned int j = 0; j < cols; ++j)
        {
            delete cells[i][j];
        }
        delete [] cells[i];
    }
    delete [] cells;
    cells = nullptr;
}

Field &Field::operator=(Field &other) {
    std::cout << "!!!copy operator\n";
    if (this != &other)
    {
        // free memory
        for (unsigned int i = 0; i < rows; ++i)
        {
            for (unsigned int j = 0; j < cols; ++j)
            {
                delete cells[i][j];
            }
            delete [] cells[i];
        }
        delete [] cells;
        cells = nullptr;

        // assigment
        cells = new Cell**[rows];
        for (unsigned int i = 0; i < rows; ++i)
        {
            cells[i] = new Cell *[cols];
            for (unsigned int j = 0; j < cols; ++j)
            {
                cells[i][j] = other.cells[i][j]->clone();
            }
        }
    }
    return *this;
}

Field::Field(Field &&other)  noexcept {
    std::cout << "!!!move constructor\n";
    std::swap(rows, other.rows);
    std::swap(cols, other.cols);
    std::swap(walls_percentage,other.walls_percentage);
    std::swap(this->cells, other.cells);
}

Field &Field::operator=(Field &&other)  noexcept {
    std::cout << "!!!move operator\n";
    if (this != &other)
    {
        std::swap(rows, other.rows);
        std::swap(cols, other.cols);
        std::swap(walls_percentage,other.walls_percentage);
        std::swap(this->cells, other.cells);
    }
}

const Cell *const Field::get_cell(unsigned int x, unsigned int y) {
    if (x < rows and y < cols) return cells[x][y];
    else return nullptr;
}

unsigned int get_random_int(unsigned int min_int_included, unsigned int max_int_included)
{
    static std::random_device rd;// only used once to initialise (seed) engine
    std::uniform_int_distribution<int> uni(static_cast<int>(min_int_included),
                                           static_cast<int>(max_int_included)); // guaranteed unbiased

    return uni(rd);
}