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

nlohmann::json Cell::get_json_repr() const{
    nlohmann::json cell_repr = {};
    cell_repr["type"] =  "Cell";
    cell_repr["has_entity"] = this->entity != nullptr;
    cell_repr["has_item"] = this->has_item;

    if (this->entity != nullptr)
    {
        cell_repr["entity"] = entity->get_json_repr();
    }
    return cell_repr;
}

