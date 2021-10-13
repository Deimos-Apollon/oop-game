//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_CELL_H
#include <iostream>
#define OOP_GAME_CELL_H

class Entity;

class Cell {
protected:
    unsigned int row;
    unsigned int col;
    bool vacant;
    bool has_item = false;
    Entity* entity = nullptr;
public:
    Cell(unsigned int row, unsigned int col, bool vacant=true);
    virtual ~Cell() = default;
    void set_entity(Entity* entity1) { this->entity = entity1; };
    const Entity* const get_entity() const { return entity; }
    unsigned int get_row() const { return row; }
    unsigned int get_col() const { return col; }
    bool is_vacant() const { return vacant; }
    bool if_has_item() const { return has_item; };
    void set_has_item(bool has_item) { this->has_item = has_item; };
    virtual Cell* clone();
    virtual unsigned int getID() const;
};


#endif //OOP_GAME_CELL_H
