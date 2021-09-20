//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_CELL_H
#define OOP_GAME_CELL_H


#include <iostream>

class Cell {
    unsigned int x;
    unsigned int y;
    bool is_vacant;
    // Entity* ent
public:
    Cell(unsigned int x, unsigned int y, bool is_vacant=true);
    virtual void interact() { std::cout << "*";};
};


#endif //OOP_GAME_CELL_H
