//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_CELL_H
#include <iostream>
#include "../../../entities/Items/Item/Item.h"
#include "../../../entities/Creatures/Player/Player.h"
#include "../../../Game/GameSerialising/GameSaverLoaderJSON/JSONSaveableInterface/JSONSaveableInterface.h"

#include <map>
#define OOP_GAME_CELL_H

class Cell : JSONSaveableInterface {
protected:
    unsigned int row;
    unsigned int col;
    bool vacant;
    bool has_item = false;
    Entity* entity = nullptr;

public:
    Cell(unsigned int row, unsigned int col, bool vacant=true);
    virtual ~Cell() = default;
    void set_creature(Entity* entity1);
    void set_item(Entity* entity1);

    const Entity* const get_entity() const{ return entity; };

    unsigned int get_row() const { return row; }
    unsigned int get_col() const { return col; }

    bool is_vacant() const { return vacant; }
    bool if_has_item() const { return has_item; };

    void set_has_item(bool has_item) { this->has_item = has_item; };
    void set_is_vacant(bool arg_vacant) { this->vacant = arg_vacant; };

    void attach_item_to_player(Player* player, map <Item*, pair<unsigned int, unsigned int>> &items);
    virtual Cell* clone();

    nlohmann::json get_json_repr() const override;
};


#endif //OOP_GAME_CELL_H
