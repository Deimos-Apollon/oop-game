//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_ENTERCELL_H
#define OOP_GAME_ENTERCELL_H


#include "../Cell/Cell.h"

class EnterCell : public Cell{
public:
    EnterCell(unsigned int x, unsigned int y, bool vacant=true) : Cell(x,y, vacant) {};
    ~EnterCell() override = default;
    virtual Cell* clone();
    nlohmann::json get_json_repr() const override;
};


#endif //OOP_GAME_ENTERCELL_H
