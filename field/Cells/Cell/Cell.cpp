//
// Created by deimos on 19.09.2021.
//

#include "Cell.h"

Cell::Cell(unsigned int row, unsigned int col, bool vacant): row(row), col(col), vacant(vacant)
{

}

Cell* Cell::clone() {
    Cell* tmp = new Cell(this->row, this->col);
    return tmp;
}


void Cell::set_creature(Entity *entity1) {
    if (entity1 != nullptr) {
        vacant = false;
    }
    else {
        vacant = true;
        has_item = false;
    }
    this->entity = entity1;
}

void Cell::set_item(Entity *entity1) {
    vacant = true;
    has_item = (entity1 != nullptr);
    this->entity = entity1;
}

void Cell::attach_item_to_player(Player *player, map<Item *, pair<unsigned int, unsigned int>> &items) {
    player->add_item(dynamic_cast<Item *>(entity));     // TODO mind if good
    items.erase(dynamic_cast<Item *>(entity));
    this->entity = nullptr;
    this->has_item = false;
}

