//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_INTFIELD_H
#include "../../field/Field.h"
#include "../CLI_Printable.h"

#define OOP_GAME_INTFIELD_H


class FieldView : CLI_Printable{
    Field& field;
public:
    explicit FieldView(Field& field) : field(field) {};
    void print() override;
};


#endif //OOP_GAME_INTFIELD_H
