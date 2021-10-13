//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_ENTITY_H
#include "../field/Cells/Cell.h"
#define OOP_GAME_ENTITY_H



class Entity {
protected:
    Cell* cell;
    Entity(): cell(nullptr) {};
    explicit Entity(Cell* cell_p): cell(cell_p) {};
public:
    unsigned int get_row() { return cell->get_row(); }
    unsigned int get_col() { return cell->get_col(); }
    void set_cell(Cell* other_cell) {cell = other_cell; };
    virtual ~Entity();

};


#endif //OOP_GAME_ENTITY_H
