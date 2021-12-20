//
// Created by deimos on 14.12.2021.
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include "GameSaverLoaderJSON.h"
#include "../../../field/Cells/Cell/Cell.h"
#include "../../../field/Cells/Wall/Wall.h"
#include "../../../field/FieldBuilder/FieldBuilder.h"


bool GameSaverLoaderJSON::load_game(FieldInterface* &field, Player* &player, const string &filename) {
    std::ifstream file(filename);

    bool valid = true;
    if (file.is_open()) {

        Player *new_player = nullptr;
        unsigned int player_row = 0, player_col = 0;
        json data_json;
        file >> data_json;
        json field_json = data_json["field"];
        if (field_json.is_null()) return false;
        size_t rows = field_json["rows"];
        size_t cols = field_json["cols"];
        size_t number = field_json["number"];


        json cells_json = field_json["cells"];
        std::vector<Cell*> cells;
        map <Enemy*, pair<unsigned int, unsigned int>> enemies;
        unsigned int enemies_num = 0;

        FieldBuilder fb;
        size_t row = 0, col = 0;

        for (auto cell_json: cells_json)
        {
            if (col == cols)
            {
                col = 0;
                ++row;
            }
            std::string type = cell_json["type"];
            bool has_item = cell_json["has_item"];
            bool is_vacant = cell_json["is_vacant"];
            json entity = cell_json["entity"];
            Entity* new_entity = nullptr;
            Cell* new_cell = nullptr;
            if (type == "Cell")
            {
                new_cell = new Cell(row, col, is_vacant);
            }
            else if (type == "Wall")
            {
                new_cell = new Wall(row, col);
            }
            else if (type == "EnterCell")
            {
                new_cell = new EnterCell(row, col, is_vacant);
            }
            else if (type == "ExitCell")
            {
                new_cell = new ExitCell(row, col, is_vacant);
            }

            if (!entity.is_null()) {
                auto entity_type = entity["type"];
                if (entity_type == "Player") {
                    int armor = entity["armor"];
                    unsigned int curr_hp = entity["curr_hp"];
                    unsigned int damage = entity["base_attack_damage"];
                    auto items = entity["items"];
                    auto max_hp = entity["max_hp"];
                    new_entity = new Player(max_hp, armor, damage);
                    new_player = dynamic_cast<Player *>(new_entity);
                    if (!items.is_null())
                    {
                        for (auto item: items)
                        {
                            auto item_type = item["type"];
                            if (item_type == "RestorationWand")
                            {
                                unsigned int heal_power = item["heal_power"];
                                // unsigned int range = entity["range"];
                                unsigned int usages = item["usages"];
                                auto new_item = new RestorationWand(heal_power, usages);
                                new_player->add_item(new_item);
                            }
                            else if (item_type == "Bow")
                            {
                                unsigned int damage = item["damage"];
                                unsigned int range = item["range"];
                                unsigned int usages = item["usages"];
                                auto new_item = new Bow(range, damage, usages);
                                new_player->add_item(new_item);
                            }
                        }
                    }

                    new_cell->set_creature(new_entity);
                    player_row = row; player_col = col;
                }
                else if (entity_type == "MageHealer")
                {
                    auto armor = entity["armor"];
                    auto attack_range = entity["attack_range"];
                    auto damage = entity["base_attack_damage"];
                    auto curr_hp = entity["curr_hp"];
                    auto max_hp = entity["max_hp"];
                    auto new_enemy = new MageHealer(max_hp,armor,damage, attack_range);
                    new_cell->set_creature(new_enemy);
                    enemies.insert({new_enemy, {row, col}});
                }
                else if (entity_type == "MeleeSkeleton")
                {
                    auto armor = entity["armor"];
                    auto attack_range = entity["attack_range"];
                    auto damage = entity["base_attack_damage"];
                    auto curr_hp = entity["curr_hp"];
                    auto max_hp = entity["max_hp"];
                    auto new_enemy = new MeleeSkeleton(max_hp,armor,damage, attack_range);
                    new_cell->set_creature(new_enemy);
                    enemies.insert({new_enemy, {row, col}});
                }
                else if (entity_type == "ArcherSkeleton")
                {
                    auto armor = entity["armor"];
                    auto attack_range = entity["attack_range"];
                    auto damage = entity["base_attack_damage"];
                    auto curr_hp = entity["curr_hp"];
                    auto max_hp = entity["max_hp"];
                    auto new_enemy = new ArcherSkeleton(max_hp,armor,damage, attack_range);
                    new_cell->set_creature(new_enemy);
                    enemies.insert({new_enemy, {row, col}});;
                }
                else if (entity_type == "RestorationWand")
                {
                    unsigned int heal_power = entity["heal_power"];
                    // unsigned int range = entity["range"];
                    unsigned int usages = entity["usages"];
                    new_entity = new RestorationWand(heal_power, usages);
                    new_cell->set_item(new_entity);
                }
                else if (entity_type == "Bow")
                {
                    unsigned int damage = entity["damage"];
                    unsigned int range = entity["range"];
                    unsigned int usages = entity["usages"];
                    new_entity = new Bow(range, damage, usages);
                    new_cell->set_item(new_entity);
                }
            }
            cells.push_back(new_cell);
            ++col;
        }

        fb.add_cells(cells, rows, cols);
        fb.add_player(new_player, player_row, player_col);
        fb.add_enemies(enemies);
        fb.set_number(number);

        Field* new_field = fb.get_result();
        field = new_field;
        player = new_player;

    }
    file.close();
    return true;
}

void GameSaverLoaderJSON::save_game(FieldInterface* field, const string &filename) {
    std::ofstream file(filename);
    if (file.is_open())
    {
        json field_view;
        field_view = field->get_json_repr();
        file << std::setw(4) << field_view << std::endl;
    }
    file.close();
}

bool GameSaverLoaderJSON::can_load_file(const std::string& filename) {
    std::ifstream file(filename);

    bool valid = true;
    if (file.is_open()) {

        Player *new_player = nullptr;
        unsigned int player_row = 0, player_col = 0;
        json data_json;
        try {
            file >> data_json;
            json field_json = data_json["field"];
            try {
                size_t rows = field_json["rows"];
                size_t cols = field_json["cols"];
                size_t number = field_json["number"];
                json cells_json = field_json["cells"];
                std::vector<Cell *> cells;
                map<Enemy *, pair<unsigned int, unsigned int>> enemies;
                unsigned int enemies_num = 0;

                FieldBuilder fb;
                size_t row = 0, col = 0;

                for (auto cell_json: cells_json) {
                    if (col == cols) {
                        col = 0;
                        ++row;
                    }
                    std::string type = cell_json["type"];
                    bool has_item = cell_json["has_item"];
                    bool is_vacant = cell_json["is_vacant"];
                    json entity = cell_json["entity"];
                    Entity *new_entity = nullptr;
                    Cell *new_cell = nullptr;
                    if (type == "Cell") {
                        new_cell = new Cell(row, col, is_vacant);
                    } else if (type == "Wall") {
                        new_cell = new Wall(row, col);
                    } else if (type == "EnterCell") {
                        new_cell = new EnterCell(row, col, is_vacant);
                    } else if (type == "ExitCell") {
                        new_cell = new ExitCell(row, col, is_vacant);
                    }
                    else
                    {
                        for (auto enemy: enemies)
                        {
                            delete enemy.first;
                        }
                        for (auto cell: cells)
                        {
                            delete cell;
                        }
                        return false;
                    }
                    if (!entity.is_null()) {
                        auto entity_type = entity["type"];
                        if (entity_type == "Player") {
                            if (new_player != nullptr)
                            {
                                return false;
                            }
                            int armor = entity["armor"];
                            unsigned int curr_hp = entity["curr_hp"];
                            auto items = entity["items"];
                            auto max_hp = entity["max_hp"];
                            new_entity = new Player(max_hp, armor);
                            new_player = dynamic_cast<Player *>(new_entity);
                            if (!items.is_null()) {
                                for (auto item: items) {
                                    auto item_type = item["type"];
                                    if (item_type == "RestorationWand") {
                                        unsigned int heal_power = item["heal_power"];
                                        // unsigned int range = entity["range"];
                                        unsigned int usages = item["usages"];
                                        auto new_item = new RestorationWand(heal_power, usages);
                                        new_player->add_item(new_item);
                                    } else if (item_type == "Bow") {
                                        unsigned int damage = item["damage"];
                                        unsigned int range = item["range"];
                                        unsigned int usages = item["usages"];
                                        auto new_item = new Bow(range, damage, usages);
                                        new_player->add_item(new_item);
                                    }
                                }
                            }

                            new_cell->set_creature(new_entity);
                            player_row = row;
                            player_col = col;
                        } else if (entity_type == "MageHealer") {
                            auto armor = entity["armor"];
                            auto attack_range = entity["attack_range"];
                            auto damage = entity["base_attack_damage"];
                            auto curr_hp = entity["curr_hp"];
                            auto max_hp = entity["max_hp"];
                            auto new_enemy = new MageHealer(max_hp, armor, damage, attack_range);
                            new_cell->set_creature(new_enemy);
                            enemies.insert({new_enemy, {row, col}});
                        } else if (entity_type == "MeleeSkeleton") {
                            auto armor = entity["armor"];
                            auto attack_range = entity["attack_range"];
                            auto damage = entity["base_attack_damage"];
                            auto curr_hp = entity["curr_hp"];
                            auto max_hp = entity["max_hp"];
                            auto new_enemy = new MeleeSkeleton(max_hp, armor, damage, attack_range);
                            new_cell->set_creature(new_enemy);
                            enemies.insert({new_enemy, {row, col}});
                        } else if (entity_type == "ArcherSkeleton") {
                            auto armor = entity["armor"];
                            auto attack_range = entity["attack_range"];
                            auto damage = entity["base_attack_damage"];
                            auto curr_hp = entity["curr_hp"];
                            auto max_hp = entity["max_hp"];
                            auto new_enemy = new ArcherSkeleton(max_hp, armor, damage, attack_range);
                            new_cell->set_creature(new_enemy);
                            enemies.insert({new_enemy, {row, col}});;
                        } else if (entity_type == "RestorationWand") {
                            unsigned int heal_power = entity["heal_power"];
                            // unsigned int range = entity["range"];
                            unsigned int usages = entity["usages"];
                            new_entity = new RestorationWand(heal_power, usages);
                            new_cell->set_item(new_entity);
                        } else if (entity_type == "Bow") {
                            unsigned int damage = entity["damage"];
                            unsigned int range = entity["range"];
                            unsigned int usages = entity["usages"];
                            new_entity = new Bow(range, damage, usages);
                            new_cell->set_item(new_entity);
                        }
                        else
                        {
                            for (auto enemy: enemies)
                            {
                                delete enemy.first;
                            }
                            for (auto cell: cells)
                            {
                                delete cell;
                            }
                            return false;
                        }
                    }
                    cells.push_back(new_cell);
                    ++col;
                }
                for (auto enemy: enemies)
                {
                    delete enemy.first;
                }
                for (auto cell: cells)
                {
                    delete cell;
                }
                if ((row != rows - 1) || (col != cols)) return false;
            }
            catch (nlohmann::detail::type_error) {
                return false;
            }
        } catch (nlohmann::detail::parse_error) { return false; }
    } else valid = false;
    file.close();
    return valid;
}
