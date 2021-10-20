//
// Created by Deimos on 16.10.2021.
//

#include "FieldBuilder.h"



void FieldBuilder::create_path(unsigned int row_ent, unsigned int col_ent, unsigned int row_exit, unsigned int col_exit) {
    auto tmp_x = row_ent, tmp_y = col_ent;
    while(true){
        if (randomer.get_random_int(1, 2) == 1){
            tmp_x += row_exit > tmp_x ? 1 : -1;       // if exit is left from enter, move left, otherwise right
            if (tmp_x == 0) ++tmp_x;
        } else {
            tmp_y += col_exit > tmp_y ? 1 : -1;       // if exit is above enter, move up, else move down
            if (tmp_y == 0) ++tmp_y;
        }
        if (tmp_x == row_exit && tmp_y == col_exit)
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

Cell *FieldBuilder::get_random_vacant_cell() {
    auto row = randomer.get_random_int(1, rows-1);
    auto col = randomer.get_random_int(1, cols-1);
    while (!cells[row][col]->is_vacant() || cells[row][col]->if_has_item() || cells[row][col] == exit_cell)
    {
        row = randomer.get_random_int(1, rows-1);
        col = randomer.get_random_int(1, cols-1);
    }
    return cells[row][col];
}

void FieldBuilder::create_cells(unsigned int new_rows, unsigned int new_cols, unsigned int walls_percentage) {
    auto rows_with_walls = new_rows + 2;
    auto cols_with_walls = new_cols + 2;
    cells = new Cell**[rows_with_walls];

    cols = new_cols;
    rows = new_rows;
    if (new_rows == 1 && new_cols == 1)
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
    else if (new_rows < 1 || new_cols < 1)
    {
        std::cout << "Error, incorrect rows or new_cols";
    }
    else {
        // declare cells
        for (unsigned int i = 0; i < rows_with_walls; ++i) {
            cells[i] = new Cell *[cols_with_walls];
        }
        // init cells
        for (unsigned int i = 1; i < rows_with_walls - 1; ++i) {
            for (unsigned int j = 1; j < cols_with_walls - 1; ++j) {
                if (randomer.get_random_int(1, 100) > walls_percentage)
                    cells[i][j] = new Cell(i, j);
                else {
                    cells[i][j] = new Wall(i, j);
                }
            }
        }

        // init enter and exit cells coordinates
        unsigned int scalar = (new_cols != 1 && new_rows != 1) ? 2 : ((new_cols == 1) ? rows_with_walls : cols_with_walls);
        unsigned int row_ent = 1, col_ent = 1, row_exit = 1, col_exit = 1;
        while (abs(int(row_ent - row_exit)) < ((rows_with_walls) / scalar) ||
               abs(int(col_ent - col_exit)) < ((cols_with_walls) / scalar)) {
            row_ent = randomer.get_random_int(1, rows_with_walls - 2);
            col_ent = randomer.get_random_int(1, cols_with_walls - 2);
            row_exit = randomer.get_random_int(1, rows_with_walls - 2);
            col_exit = randomer.get_random_int(1, cols_with_walls - 2);
        }

        // add exit and enter cells in cells
        delete cells[row_ent][col_ent];
        cells[row_ent][col_ent] = new EnterCell(row_ent, col_ent);
        enter_cell = cells[row_ent][col_ent];

        delete cells[row_exit][col_exit];
        cells[row_exit][col_exit] = new ExitCell(row_exit, col_exit);
        exit_cell = cells[row_exit][col_exit];

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
        this->create_path(row_ent, col_ent, row_exit, col_exit);
    }
}

void FieldBuilder::add_enemy(Enemy *enemy, unsigned int row, unsigned int col) {
    if (row == 0 || col == 0)
    {
        auto new_cell = get_random_vacant_cell();
        row = new_cell->get_row();
        col = new_cell->get_col();
    }
    enemies[enemy] = pair<unsigned int, unsigned int>(row, col);
    cells[row][col]->set_creature(enemy);
    ++enemies_num;
}

void FieldBuilder::add_enemy(Enemy *enemy, Cell *cell) {
    if (cell == nullptr)
    {
        cell = get_random_vacant_cell();
    }
    enemies[enemy] = pair<unsigned int, unsigned int>(cell->get_row(), cell->get_col());
    cell->set_creature(enemy);
    ++enemies_num;
}

void FieldBuilder::add_item(Item *item, Cell *cell) {
    if (cell == nullptr)
    {
        cell = get_random_vacant_cell();
    }
    items[item] = pair<unsigned int, unsigned int>(cell->get_row(), cell->get_col());
    cell->set_item(item);
    cell->set_has_item(true);
}

void FieldBuilder::add_item(Item *item, unsigned int row, unsigned int col) {
    if (row == 0 || col == 0)
    {
        auto new_cell = get_random_vacant_cell();
        row = new_cell->get_row();
        col = new_cell->get_col();
    }
    cells[row][col]->set_item(item);
    cells[row][col]->set_has_item(true);
    items[item] = pair<unsigned int, unsigned int>(row, col);
}

void FieldBuilder::add_player(Player *player) {
    this->player = player;
    enter_cell->set_creature(this->player);
    enter_cell->set_is_vacant(false);
    player_coords = {enter_cell->get_row(), enter_cell->get_col()};
}

void FieldBuilder::add_enemy_MeleeSkeleton(unsigned int row, unsigned int col) {
    add_enemy(new MeleeSkeleton(), row, col);
}

void FieldBuilder::add_enemy_ArcherSkeleton(unsigned int row, unsigned int col) {
    add_enemy(new ArcherSkeleton(), row, col);
}

void FieldBuilder::add_enemy_MageHealer(unsigned int row, unsigned int col) {
    add_enemy(new MageHealer(), row, col);
}

void FieldBuilder::add_Axe(unsigned int row, unsigned int col) {
    add_item(new Axe(), row, col);
}

void FieldBuilder::add_RestorationWand(unsigned int row, unsigned int col) {
    add_item(new RestorationWand(), row, col);
}

void FieldBuilder::add_Bow(unsigned int row, unsigned int col) {
    add_item(new Bow(), row, col);
}

Field *FieldBuilder::get_result() {
    Field* field = nullptr;
    if (player != nullptr && cells != nullptr) {
        field = new Field(player, player_coords, enemies, enemies_num, items, cells, enter_cell, exit_cell, rows, cols);
    }
    clear();
    return field;
}

void FieldBuilder::clear() {
    rows = 0;
    cols = 0;
    walls_percentage = 30; // 0 to 90
    cells = nullptr;
    enter_cell = nullptr;
    exit_cell = nullptr;
    player = nullptr;
    enemies = {};
    items = {};
    enemies_num = 0;
}

