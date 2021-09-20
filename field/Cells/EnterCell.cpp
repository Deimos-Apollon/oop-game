//
// Created by deimos on 19.09.2021.
//

#include "EnterCell.h"

EnterCell::EnterCell(unsigned int x, unsigned int y): Cell(x, y){

}

void EnterCell::interact() {
    std::cout << "-";
}