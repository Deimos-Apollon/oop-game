//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_FIELD_H

#include "../Cells/Cell/Cell.h"
#include "../Cells/ExitCell/ExitCell.h"
#include "../Cells/EnterCell/EnterCell.h"
#include "../Cells/Wall/Wall.h"

#include "../../entities/Creatures/Player/Player.h"

#include <map>

#include "../../ClassesHelpers/Randomer.h"
#include "../../entities/Creatures/Enemies/Enemy/Enemy.h"
#include "../FieldInterface/FieldInterface.h"

#include "../../entities/Creatures/Enemies/AIStrategy/StrategiesManager/StrategiesManager.h"
#include "../../entities/Creatures/Enemies/AIStrategy/AIStrategy.h"
#include "../../entities/Creatures/Enemies/AIStrategy/ApproachStrategy/ApproachStrategy.h"
#include "../../entities/Creatures/Player/PlayerController/PlayerController.h"


#define OOP_GAME_FIELD_H

using namespace std;


class Field : public FieldInterface{
protected:

    unsigned int rows = 0;
    unsigned int cols = 0;

    Cell*** cells = nullptr;
    Cell* enter_cell = nullptr;
    Cell* exit_cell = nullptr;

    Player* player;
    pair <unsigned int, unsigned int> player_coords;
    PlayerController* player_controller;

    map <Enemy*, pair<unsigned int, unsigned int>> enemies = {};
    map <Item*, pair<unsigned int, unsigned int>> items = {};
    unsigned int enemies_num = 0;

    StrategiesManager strategies_manager;

    void proceed();
    void finish();
public:
    Field(Player* player, pair <unsigned int, unsigned int> player_coords, map <Enemy*, pair<unsigned int, unsigned int>> enemies, unsigned int enemies_num,
          map <Item*, pair<unsigned int, unsigned int>> items, Cell*** cells, Cell* enter_cell, Cell* exit_cell,
          unsigned int rows, unsigned int cols);

    Field(Field& other);                            // TODO CHANGE
    Field& operator=(Field& other);
    Field(Field&& other) noexcept ;
    Field& operator=(Field&& other) noexcept ;
    ~Field();

    void start() override;

    unsigned int get_rows() const { return rows; }
    unsigned int get_cols() const { return cols; }
    const Cell* const get_cell(unsigned int row, unsigned int col);

    void move_player(int drow,  int dcol) override;
    void move_enemy(Enemy* enemy,  int drow,  int dcol) override;

    void player_attack_nearest_enemy() override;

    void wounded_enemy_restore_health(unsigned int health) override;

    int calculate_distance_from_player(Enemy* enemy);
    pair<int,int> calculate_differ_in_distance_with_player(Enemy* enemy) override;
};


#endif //OOP_GAME_FIELD_H
