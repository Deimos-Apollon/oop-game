//
// Created by Deimos on 16.10.2021.
//

#ifndef OOP_GAME_FIELDBUILDER_H
#include "../Field/Field.h"
#include "../../entities/Creatures/Enemies/MeleeSkeleton/MeleeSkeleton.h"
#include "../../entities/Creatures/Enemies/ArcherSkeleton/ArcherSkeleton.h"

#include "../../entities/Items/HealItems/RestorationWand.h"

#define OOP_GAME_FIELDBUILDER_H


class FieldBuilder {
    unsigned int rows = 0;
    unsigned int cols = 0;
    unsigned int walls_percentage = 30; // 0 to 90
    Cell*** cells = nullptr;
    Cell* enter_cell = nullptr;
    Cell* exit_cell = nullptr;

    Player* player = nullptr;
    pair <unsigned int, unsigned int> player_coords;

    map <Enemy*, pair<unsigned int, unsigned int>> enemies = {};
    map <Item*, pair<unsigned int, unsigned int>> items = {};
    unsigned int enemies_num = 0;

    Randomer randomer;
private:
    void create_path(unsigned x_ent, unsigned y_ent,
                     unsigned x_exit, unsigned y_exit);

    void add_enemy(Enemy* enemy, Cell* cell = nullptr);
    void add_enemy(Enemy* enemy, unsigned int row = 0, unsigned int col = 0);

    void add_item(Item* item,  Cell* cell = nullptr);
    void add_item(Item* item, unsigned int row = 0, unsigned int col = 0);

    Cell* get_random_vacant_cell();

    void clear();
public:
    void create_cells(unsigned int rows, unsigned int cols, unsigned  int walls_percentage = 30);

    void add_player(Player* player);

    void add_enemy_MeleeSkeleton(unsigned int row = 0, unsigned int col = 0);
    void add_enemy_ArcherSkeleton(unsigned int row = 0, unsigned int col = 0);

    void add_Axe(unsigned int row = 0, unsigned int col = 0);
    void add_RestorationWand(unsigned int row = 0, unsigned int col = 0);

    Field* get_result();

};


#endif //OOP_GAME_FIELDBUILDER_H
