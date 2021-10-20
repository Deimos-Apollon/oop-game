//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_INTFIELD_H
#include "../../field/Field/Field.h"
#include "../CLI_Printable/CLI_Printable.h"
#include "../../field/FieldIterator/FieldIterator.h"

#include "../../entities/Creatures/Enemies/Enemy/Enemy.h"
#include "../../entities/Creatures/Enemies/Enemies_types/MeleeSkeleton/MeleeSkeleton.h"
#include "../../entities/Creatures/Enemies/Enemies_types/ArcherSkeleton/ArcherSkeleton.h"
#include "../../entities/Creatures/Enemies/Enemies_types/MageHealer/MageHealer.h"

#include "../../entities/Items/MeleeDamageItems/Axe/Axe.h"
#include "../../entities/Items/HealItems/RestorationWand.h"
#include "../../entities/Items/Bow/Bow.h"

#include <map>
#define OOP_GAME_INTFIELD_H

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
