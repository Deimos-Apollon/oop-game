//
// Created by deimos on 20.09.2021.
//

#include "FieldView.h"
#include "../../field/FieldIterator.h"

void FieldView::print() {
    FieldIterator fi(field);
    auto it_cell = fi.next();
    auto counter = 1;
    auto new_line_border = fi.get_cols();

    while(it_cell != nullptr){
        std::cout << cell_symbols[it_cell->getID()];
        if (counter == new_line_border)
        {
            std::cout << "\n";
            counter = 0;
        }
        ++counter;
        it_cell = ++fi;
    }

}

FieldView::FieldView(FieldIterator &field): field(field) {
    cell_symbols = { {0, ' '},         // Cell
                     {1, 'E'},         // Exit
                     {2, 'S'},         // Start
                     {3, 'X'}          // Wall
    };
}
