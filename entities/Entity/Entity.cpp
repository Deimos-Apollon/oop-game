//
// Created by Deimos on 16.10.2021.
//

#include "Entity.h"

bool Entity::get_and_restore_has_changed() const {
    if (changed)
    {
        changed = false;
        return true;
    }
    return false;
}
