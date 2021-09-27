//
// Created by deimos on 20.09.2021.
//

#include "FieldView.h"
#include "../../field/FieldIterator.h"

void FieldView::print() {
    FieldIterator fi(field);
    auto it_cell = fi.next();
    auto counter = 1;
    auto new_line_border = field.get_cols();
    while(it_cell != nullptr){
        if (typeid(*it_cell) == typeid(Cell))
        {
            std::cout << " ";
        }
        else if (typeid(*it_cell) == typeid(Wall))
        {
            std::cout << "X";
        }
        else if (typeid(*it_cell) == typeid(ExitCell))
        {
            std::cout << "S";
        }
        else if (typeid(*it_cell) == typeid(EnterCell))
        {
            std::cout << "E";
        }
        if (counter == new_line_border)
        {
            std::cout << "\n";
            counter = 0;
        }
        ++counter;
        it_cell = fi.next();
    }

}
