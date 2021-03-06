//
// Created by deimos on 20.09.2021.
//

#include "FieldView.h"

void FieldView::print() {
    auto it_cell = fi.next();
    auto counter = 1;
    auto new_line_border = fi.get_cols();
    while(it_cell != nullptr){
        if (it_cell->get_entity()){
            std::cout << entities_symbols[typeid(*it_cell->get_entity()).name()]; }
        else
            std::cout << cell_symbols[typeid(*it_cell).name()];
        if (counter == new_line_border)
        {
            std::cout << "\n";
            counter = 0;
        }
        ++counter;
        it_cell = ++fi;
    }
}

FieldView::FieldView(FieldIterator &fi): fi(fi) {
    cell_symbols = { {typeid(Cell).name(), ' '},         // Cell
                     {typeid(ExitCell).name(), 'E'},         // Exit
                     {typeid(EnterCell).name(), 'S'},         // Start
                     {typeid(Wall).name(), 'X'}          // Wall
    };

    entities_symbols = {{typeid(Player).name(),          'P'},         // Player
                        {typeid(MeleeSkeleton).name(),   '1'},         // Enemy
                        {typeid(ArcherSkeleton).name(),  '2'},
                        {typeid(MageHealer).name(),      '3'},
                        {typeid(Axe).name(),             'A'},          // Axe
                        {typeid(RestorationWand).name(), 'R'},
                        {typeid(Bow).name(),             'B'},
    };
}
