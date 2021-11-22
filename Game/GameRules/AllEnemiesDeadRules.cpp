//
// Created by Deimos on 22.11.2021.
//

#include "AllEnemiesDeadRules.h"

bool AllEnemiesDeadRules::tasks_complited() {
    if (field->get_enemies_num() == 0 && field->player_stands_on_exit())
    {
        return true;
    }
    return false;
}

