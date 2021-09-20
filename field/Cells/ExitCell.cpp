//
// Created by deimos on 19.09.2021.
//

#include "ExitCell.h"

ExitCell::ExitCell(unsigned int x, unsigned int y): Cell(x, y) {

}

void ExitCell::interact() {
    std::cout << "!";
}
