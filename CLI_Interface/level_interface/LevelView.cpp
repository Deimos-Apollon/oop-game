//
// Created by Deimos on 12.10.2021.
//

#include "LevelView.h"

void LevelView::print() {
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

LevelView::LevelView(FieldIterator &fi_p) : FieldView(fi_p) {
    entities_symbols = {
            { typeid(Player).name(), 'P'},         // Player
            { typeid(Enemy).name(), '1'},         // Enemy
            { typeid(Axe).name(), 'A'},          // Axe

    };
}
