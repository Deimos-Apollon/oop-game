//
// Created by Deimos on 22.11.2021.
//

#ifndef OOP_GAME_ALLENEMIESDEADRULES_H
#define OOP_GAME_ALLENEMIESDEADRULES_H


#include "../../field/FieldInterface/FieldInterface.h"

template<class T>
class AllEnemiesDeadRules {
    FieldInterface *field = nullptr;
    T number = 0;
public:
    bool tasks_complited() {
        if (field->get_enemies_num() == number) {
            return true;
        }
        return false;
    }
    void set_field(FieldInterface* field) { this->field = field; }
    void set_number(T arg_number) { number = arg_number; }
};


#endif //OOP_GAME_ALLENEMIESDEADRULES_H
