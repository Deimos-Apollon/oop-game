//
// Created by Deimos on 17.10.2021.
//

#ifndef OOP_GAME_FIELDINTERFACE_H
#define OOP_GAME_FIELDINTERFACE_H


#include "../../entities/Creatures/Player/Player.h"
#include "../../entities/Creatures/Enemies/Enemy/Enemy.h"

class FieldInterface {
public:
    virtual ~FieldInterface() = default;

    virtual void move_player(int drow,  int dcol) {};
    virtual void move_enemy(Enemy* enemy,  int drow,  int dcol) {};
    virtual pair<int,int> calculate_differ_in_distance_with_player(Enemy* enemy) { return {0,0}; };
    virtual void player_attack_nearest_enemy() {};

    virtual void start() {};
    virtual void proceed() = 0;
    virtual void finish() {};

    virtual void wounded_enemy_restore_health(unsigned int health) {};

    virtual unsigned int get_enemies_num() = 0;
    virtual bool player_stands_on_exit() = 0;
    virtual bool player_is_dead() = 0;
};


#endif //OOP_GAME_FIELDINTERFACE_H
