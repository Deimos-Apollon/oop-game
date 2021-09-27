//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_WALL_H
#define OOP_GAME_WALL_H

#include "Cell.h"

class Wall : public Cell {
public:
    Wall(unsigned x, unsigned y): Cell(x, y, false){};
    ~Wall() override = default;
    Cell* clone() override;
};


#endif //OOP_GAME_WALL_H
