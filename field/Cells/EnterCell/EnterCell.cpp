//
// Created by deimos on 19.09.2021.
//

#include "EnterCell.h"

Cell *EnterCell::clone() {
    Cell* tmp = new EnterCell(this->row, this->col);
    return tmp;
}

nlohmann::json EnterCell::get_json_repr() const {
    nlohmann::json cell_repr = {};
    cell_repr["type"] =  "EnterCell";
    cell_repr["has_entity"] = this->entity != nullptr;
    cell_repr["has_item"] = this->has_item;
    cell_repr["is_vacant"] = this->vacant;

    if (this->entity != nullptr)
    {
        cell_repr["entity"] = entity->get_json_repr();
    }
    return cell_repr;
}
