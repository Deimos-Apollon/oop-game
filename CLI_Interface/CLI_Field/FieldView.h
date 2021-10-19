//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_INTFIELD_H
#include "../../field/Field/Field.h"
#include "../CLI_Printable/CLI_Printable.h"
#include "../../field/FieldIterator/FieldIterator.h"
#include "../../entities/Creatures/Enemies/Enemy/Enemy.h"
#include "../../entities/Items/MeleeDamageItems/Axe/Axe.h"
#include "../../entities/Creatures/Enemies/MeleeSkeleton/MeleeSkeleton.h"
#include "../../entities/Items/HealItems/RestorationWand.h"
#include "../../entities/Creatures/Enemies/ArcherSkeleton/ArcherSkeleton.h"

#define OOP_GAME_INTFIELD_H
#include <map>

class FieldView : CLI_Printable{
protected:
    FieldIterator& fi;
    std::map <std::string, char> cell_symbols;
    std::map <std::string, char> entities_symbols;
public:
    explicit FieldView(FieldIterator& fi);
    void print() override;
};


#endif //OOP_GAME_INTFIELD_H
