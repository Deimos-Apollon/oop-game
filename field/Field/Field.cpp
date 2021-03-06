//
// Created by deimos on 19.09.2021.
//

#include "Field.h"

#include <utility>
#include "../../CLI_Interface/CLI_Field/FieldView.h"
#include "../../entities/Creatures/Enemies/AIStrategy/MeleeSkeletonAgressiveStrategy/MeleeSkeletonAgressiveStrategy.h"
#include "../../entities/Creatures/Enemies/AIStrategy/ArcherSkeletonStrategy/ArcherSkeletonStrategy.h"
#include "../../entities/Creatures/Enemies/AIStrategy/MageHealerStrategy/MageHealerStrategy.h"



Field::Field(Player *player, size_t number, pair <unsigned int, unsigned int> player_coords, map<Enemy *,
             pair<unsigned int, unsigned int>> enemies, unsigned int enemies_num,
             map<Item *, pair<unsigned int, unsigned int>> items, Cell ***cells, Cell *enter_cell, Cell *exit_cell,
             unsigned int rows, unsigned int cols, Logger* logger):
             player(player), number(number), player_coords(std::move(player_coords)), enemies(std::move(enemies)),
             enemies_num(enemies_num), items(std::move(items)),
             cells(cells), enter_cell(enter_cell), exit_cell(exit_cell), rows(rows + 2), cols(cols + 2),
             logger(logger)
{

}

Field::Field(Field &other, Logger& logger) : rows(other.rows), cols(other.cols), logger(other.logger){
    cells = new Cell**[rows];
    for (unsigned int i = 0; i < rows; ++i)
    {
        cells[i] = new Cell *[cols];
        for (unsigned int j = 0; j < cols; ++j)
        {
            cells[i][j] = other.cells[i][j]->clone();
        }
    }
}

Field::~Field() {
    // delete cells
    for (unsigned int i = 0; i < rows; ++i)
    {
        for (unsigned int j = 0; j < cols; ++j)
        {
            delete cells[i][j];
        }
        delete [] cells[i];
    }
    delete [] cells;
    cells = nullptr;
    enter_cell = nullptr;
    exit_cell = nullptr;

    //delete enemies if exists
    for (auto enemy_pair: enemies)
    {
        delete enemy_pair.first;
    }
    enemies = {};

    // delete items
    for (auto item_pair: items)
    {
        delete item_pair.first;
    }
    items = {};


}

Field &Field::operator=(Field &other) {
    if (this != &other)
    {
        // free memory
        for (unsigned int i = 0; i < rows; ++i)
        {
            for (unsigned int j = 0; j < cols; ++j)
            {
                delete cells[i][j];
            }
            delete [] cells[i];
        }
        delete [] cells;
        cells = nullptr;

        // assigment
        cells = new Cell**[rows];
        for (unsigned int i = 0; i < rows; ++i)
        {
            cells[i] = new Cell *[cols];
            for (unsigned int j = 0; j < cols; ++j)
            {
                cells[i][j] = other.cells[i][j]->clone();
            }
        }
    }
    return *this;
}

Field::Field(Field &&other) noexcept: logger(other.logger) {
    std::swap(rows, other.rows);
    std::swap(cols, other.cols);
    std::swap(this->cells, other.cells);
}

Field &Field::operator=(Field &&other)  noexcept {
    if (this != &other)
    {
        std::swap(rows, other.rows);
        std::swap(cols, other.cols);
        std::swap(this->cells, other.cells);
    }
    return *this;
}


void Field::start() {
    // TODO HELLO MSG
    strategies_manager.enemies_set_strategies(enemies);

    for (auto item: items)
    {
        logger->add_subscriber(item.first);
    }                                           // TODO delete
    unsigned i = 0;
    for (auto enemy: enemies)
    {
        if (i == 2) break;
        logger->add_subscriber(enemy.first);     // TODO delete
        ++i;
    }
}

void Field::finish() {
}

void Field::proceed() {

    logger->print_console(player);
    logger->print_console(player->get_item());

    vector <Enemy*> enemies_erase = {};

    for (auto enemy_pair: enemies)
    {
        auto enemy = enemy_pair.first;
        if (enemy->get_curr_hp() == 0)
        {
            enemies_erase.push_back(enemy);
        }
    }
    for (auto enemy: enemies_erase)
    {
        delete_enemy(enemy);
        enemies_num -= 1;
    }
    for (auto enemy_pair: enemies)
    {
        auto enemy = enemy_pair.first;
        strategies_manager.step(this, enemy, player);
    }

    logger->proceed();
}

const Cell *const Field::get_cell(unsigned int row, unsigned int col) const{
    if (row < rows && col < cols) return cells[row][col];
    else return nullptr;
}

void Field::move_player( int drow, int dcol) {
    auto p_row = player_coords.first, p_col = player_coords.second;
    p_row += drow;
    p_col += dcol;
    if ( p_row > 0 && p_row < rows - 1 && p_col > 0 && p_col < cols - 1)
    {
        auto new_cell = cells[p_row][p_col];
        if (new_cell->is_vacant())
        {
            if (new_cell->if_has_item())
            {
                new_cell->attach_item_to_player(player, items);
            }
            cells[player_coords.first][player_coords.second]->set_creature(nullptr);
            player_coords = {p_row, p_col};
            new_cell->set_creature(player);
        }
    }
}

void Field::move_enemy(Enemy *enemy,  int drow,  int dcol) {
    auto e_row = enemies[enemy].first, e_col = enemies[enemy].second;
    e_row += drow;
    e_col += dcol;
    if ( e_row > 0 && e_row < rows - 1 && e_col > 0 && e_col < cols - 1)
    {
        auto new_cell = cells[e_row][e_col];
        if (new_cell->is_vacant() && !new_cell->if_has_item())
        {
            cells[enemies[enemy].first][enemies[enemy].second]->set_creature(nullptr);
            enemies[enemy] = pair <unsigned int, unsigned int> (e_row, e_col);
            new_cell->set_creature(enemy);
        }
    }
}

int Field::calculate_distance_from_player(Enemy *enemy) {
    auto dist = min(abs(int(player_coords.first) - int(enemies[enemy].first)), abs(int(player_coords.second) - int(enemies[enemy].second)));
    if (dist == 0)
    {
        if (int(player_coords.first) - int(enemies[enemy].first) == 0)
        {
            dist = abs(int(player_coords.second) - int(enemies[enemy].second));
        }
        else
        {
            dist = abs(int(player_coords.first) - int(enemies[enemy].first));
        }
    }
    return dist;
}

pair<int, int> Field::calculate_differ_in_distance_with_player(Enemy *enemy) {
    return { int(enemies[enemy].first) - int(player_coords.first),  int(enemies[enemy].second) - int(player_coords.second) };
}

void Field::player_attack_nearest_enemy() {
    auto min = 0;
    Enemy* min_enemy = nullptr;
    for (auto enemy_pair: enemies) {
        auto enemy = enemy_pair.first;
        auto dist = calculate_distance_from_player(enemy);
        if (min == 0 || dist < min) {
            min = dist;
            min_enemy = enemy;
        }
    }
    if (min_enemy != nullptr) {
        auto coords = calculate_differ_in_distance_with_player(min_enemy);
        player->attack(min_enemy, coords.first, coords.second);
    } else if (player->get_using_item() && player->is_item_healing()) {
        player->use_item(player, 0, 0);
    }
}


void Field::wounded_enemy_restore_health(unsigned int health) {
    auto min = -1;
    Enemy* min_enemy = nullptr;
    for (auto enemy_pair: enemies)
    {
        auto enemy = enemy_pair.first;
        if ((min == -1 || enemy->get_curr_hp() < min) && enemy->get_curr_hp() != 0 )
        {
            min = enemy->get_curr_hp();
            min_enemy = enemy;
        }
    }
    if (min_enemy != nullptr)
    {
        min_enemy->restore_health(health);
    }
}

void Field::delete_enemy(Enemy *enemy) {
    cells[enemies[enemy].first][enemies[enemy].second]->set_creature(nullptr);
    enemies.erase(enemy);
    strategies_manager.enemy_remove(enemy);

    // TODO logger.delete enemy
}

unsigned Field::get_enemies_num() {
    return enemies_num;
}

bool Field::player_stands_on_exit() {
    return (player_coords.first == exit_cell->get_row() && player_coords.second == exit_cell->get_col());
}

bool Field::player_is_dead() {
    return player->get_curr_hp() == 0;
}

nlohmann::json Field::get_json_repr() const {

    nlohmann::json cells_info;
    FieldIterator fi(*this);
    auto curr_cell = fi.next();
    while (curr_cell)
    {
        cells_info.push_back(curr_cell->get_json_repr());
        curr_cell = fi.next();
    }

    nlohmann::json field_info =
    {
            {"field",
                 {
                         {"number", number},
                         {"rows", rows},
                         {"cols", cols},
                         {"cells", cells_info}
                 }
            }
    };
    return field_info;
}

