//
// Created by deimos on 20.09.2021.
//

#include "Wall.h"

Cell *Wall::clone() {
    Cell* tmp = new Wall(this->row, this->col);
    return tmp;
}

nlohmann::json Wall::get_json_repr() const
{
    nlohmann::json cell_repr = {};
    cell_repr["type"] =  "Wall";
    cell_repr["has_entity"] = this->entity != nullptr;
    cell_repr["has_item"] = this->has_item;

    if (this->entity != nullptr)
    {
        cell_repr["entity"] = entity->get_json_repr();
    }
    return cell_repr;
}