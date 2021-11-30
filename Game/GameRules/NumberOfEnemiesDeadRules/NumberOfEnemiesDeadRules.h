//
// Created by Deimos on 22.11.2021.
//

#ifndef OOP_GAME_NUMBEROFENEMIESDEADRULES_H
#define OOP_GAME_NUMBEROFENEMIESDEADRULES_H

#include "../../../field/FieldInterface/FieldInterface.h"
#include <cstddef>

template<size_t>
class NumberOfEnemiesDeadRules {
    FieldInterface *field = nullptr;
    size_t number = 0;
public:
    NumberOfEnemiesDeadRules() = default;
    bool tasks_complited() {
        if (field->player_stands_on_exit() && field->get_enemies_num() <= number) {
            return true;
        }
        return false;
    }
    void set_field(FieldInterface* field) { this->field = field; }
    void set_number(size_t arg_number) { number = arg_number; }
};




#endif //OOP_GAME_NUMBEROFENEMIESDEADRULES_H
