//
// Created by Deimos on 23.11.2021.
//

#ifndef OOP_GAME_PICKEDITEM_H
#define OOP_GAME_PICKEDITEM_H


#include "../../../field/FieldInterface/FieldInterface.h"
#include "../../../entities/Items/Bow/Bow.h"


template<class T>
class PickedItem {
    FieldInterface *field = nullptr;
public:
    bool tasks_complited() {
        if (dynamic_cast<const T*>(field->get_players_item()) && field->player_stands_on_exit())
        {
            return true;
        }
        return false;
    }
    void set_field(FieldInterface* field) { this->field = field; }
};


#endif //OOP_GAME_PICKEDITEM_H
