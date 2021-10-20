//
// Created by Deimos on 19.10.2021.
//

#include "MageHealerStrategy.h"

void MageHealerStrategy::step(FieldInterface *field, Enemy *enemy, Player *player) {
    if (try_do_heal())
    {
        if (enemy->try_do_step())
        {
            heal(field);
            heal_cooldown = HEAL_COOLDOWN;
        }
    } else
    {
        ApproachStrategy::step(field, enemy, player);
    }
}

bool MageHealerStrategy::try_do_heal() {
    if (heal_cooldown == 0)
    {
        return true;
    }else
    {
        --heal_cooldown;
        return false;
    }
}

void MageHealerStrategy::heal(FieldInterface *field) {
    field->wounded_enemy_restore_health(HEAL_POWER);
}

