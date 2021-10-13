//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_INTFIELD_H
#include "../../field/Field.h"
#include "../CLI_Printable.h"
#include "../../field/FieldIterator.h"

#define OOP_GAME_INTFIELD_H
#include <map>

class FieldView : CLI_Printable{
protected:
    FieldIterator& fi;
    std::map <std::string, char> cell_symbols;
public:
    explicit FieldView(FieldIterator& fi);
    void print() override;
};


#endif //OOP_GAME_INTFIELD_H
