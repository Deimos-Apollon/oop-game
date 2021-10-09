//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_INTFIELD_H
#include "../../field/Field.h"
#include "../CLI_Printable.h"

#define OOP_GAME_INTFIELD_H
#include <map>

class FieldView : CLI_Printable{
    FieldIterator& field;
    std::map <unsigned int, char> cell_symbols;
public:
    explicit FieldView(FieldIterator& field);
    void print() override;
};


#endif //OOP_GAME_INTFIELD_H
