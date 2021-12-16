//
// Created by Deimos on 16.10.2021.
//

#ifndef OOP_GAME_FIELDBUILDER_H
#include "../Field/Field.h"

#include "../../entities/Items/HealItems/RestorationWand.h"
#include "../../entities/Items/Bow/Bow.h"

#include "../../entities/Creatures/Enemies/Enemies_types/MeleeSkeleton/MeleeSkeleton.h"
#include "../../entities/Creatures/Enemies/Enemies_types/ArcherSkeleton/ArcherSkeleton.h"
#include "../../entities/Creatures/Enemies/Enemies_types/MageHealer/MageHealer.h"

#define OOP_GAME_FIELDBUILDER_H


class FieldBuilder {
    unsigned int rows = 0;
    unsigned int cols = 0;
    unsigned int walls_percentage = 30; // 0 to 90
    size_t number = 0;

    Cell*** cells = nullptr;
    Cell* enter_cell = nullptr;
    Cell* exit_cell = nullptr;

    Player* player = nullptr;
    pair <unsigned int, unsigned int> player_coords;

    map <Enemy*, pair<unsigned int, unsigned int>> enemies = {};
    map <Item*, pair<unsigned int, unsigned int>> items = {};
    unsigned int enemies_num = 0;

    Logger* logger = nullptr;
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
    void add_cells(std::vector <Cell*> &cells, unsigned int rows, unsigned int cols);

    void set_number(size_t number);

    void add_player(Player* player);

    void add_player(Player* player, unsigned int player_row, unsigned int player_col);

    void add_enemies( map <Enemy*, pair<unsigned int, unsigned int>> new_enemies);
    void add_enemy_MeleeSkeleton(unsigned int row = 0, unsigned int col = 0, MeleeSkeleton* ms = nullptr);
    void add_enemy_ArcherSkeleton(unsigned int row = 0, unsigned int col = 0, ArcherSkeleton* as = nullptr);
    void add_enemy_MageHealer(unsigned int row = 0, unsigned int col = 0, MageHealer* mh = nullptr);

    void add_Axe(unsigned int row = 0, unsigned int col = 0);
    void add_RestorationWand(unsigned int row = 0, unsigned int col = 0);
    void add_Bow(unsigned int row = 0, unsigned int col = 0);

    void set_logger(Logger* new_logger);
    Field* get_result();
};


#endif //OOP_GAME_FIELDBUILDER_H
