//
// Created by Deimos on 22.11.2021.
//

#ifndef OOP_GAME_ALLENEMIESDEADRULES_H
#define OOP_GAME_ALLENEMIESDEADRULES_H


#include "../../field/FieldInterface/FieldInterface.h"

template<class T>
class AllEnemiesDeadRules {
    FieldInterface* field = nullptr;
public:
    bool tasks_complited();
    void set_field(FieldInterface* field) { this->field = field; }

};


#endif //OOP_GAME_ALLENEMIESDEADRULES_H
