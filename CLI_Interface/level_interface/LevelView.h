//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_LEVELVIEW_H
#include "../field_interface/FieldView.h"
#include "../../entities/Creatures/Enemies/Enemy/Enemy.h"
#include "../../entities/Items/MeleeDamageItems/Axe/Axe.h"

#define OOP_GAME_LEVELVIEW_H


class LevelView : FieldView{
    std::map <std::string, char> entities_symbols;
public:
    explicit LevelView(FieldIterator& fi_p);
    void print() override;
};


#endif //OOP_GAME_LEVELVIEW_H
