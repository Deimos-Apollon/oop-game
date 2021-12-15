//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_WALL_H
#define OOP_GAME_WALL_H

#include "../Cell/Cell.h"

class Wall : public Cell {
public:
    Wall(unsigned x, unsigned y): Cell(x, y, false){};
    ~Wall() override = default;
    Cell* clone() override;
    nlohmann::json get_json_repr() const override;
};


#endif //OOP_GAME_WALL_H
