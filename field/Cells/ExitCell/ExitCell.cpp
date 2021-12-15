//
// Created by deimos on 19.09.2021.
//

#include "ExitCell.h"

Cell *ExitCell::clone() {
    Cell* tmp = new ExitCell(this->row, this->col);
    return tmp;
}

nlohmann::json ExitCell::get_json_repr() const {
    nlohmann::json cell_repr = {};
    cell_repr["type"] =  "ExitCell";
    cell_repr["has_entity"] = this->entity != nullptr;
    cell_repr["has_item"] = this->has_item;

    if (this->entity != nullptr)
    {
        cell_repr["entity"] = entity->get_json_repr();
    }
    return cell_repr;
}

