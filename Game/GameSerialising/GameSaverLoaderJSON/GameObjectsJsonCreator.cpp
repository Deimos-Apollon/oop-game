//
// Created by deimos on 21.12.2021.
//

#include "GameObjectsJsonCreator.h"
#include "../../../field/FieldBuilder/FieldBuilder.h"

bool GameObjectsJsonCreator::create_data(nlohmann::json &field_json) {
    bool valid = true;
    std::vector<Cell*> cells;

    Player* new_player = nullptr;

    try {
        size_t rows = field_json["rows"];
        size_t cols = field_json["cols"];
        size_t number = field_json["number"];

        nlohmann::json cells_json = field_json["cells"];

        FieldBuilder fb;
        size_t row = 0, col = 0;

        for (auto cell_json: cells_json) {
            if (col == cols) {
                col = 0;
                ++row;
            }

            Cell* new_cell = create_cell(row, col, cell_json);

            cells.push_back(new_cell);
            ++col;
        }
        if ((row != rows - 1) || (col != cols)) valid = false;
        if (valid) {
            new_player = created_player;
            fb.add_cells(cells, rows, cols);
            fb.add_player(new_player, player_row, player_col);
            fb.add_enemies(enemies);
            fb.set_number(number);

            created_field = fb.get_result();
        } else
        {
            for (auto enemy: enemies)
            {
                delete enemy.first;
            }
            for (auto cell: cells)
            {
                delete cell;
            }
        }
    } catch (const nlohmann::detail::type_error& e)
    {
        for (auto enemy: enemies)
        {
            delete enemy.first;
        }
        for (auto cell: cells)
        {
            delete cell;
        }
        valid = false;
    }
    return valid;
}

Cell *GameObjectsJsonCreator::create_cell(size_t row, size_t col, nlohmann::json& cell_json) {
    std::string type = cell_json["type"];
    bool has_item = cell_json["has_item"];
    nlohmann::json is_vacant = cell_json["is_vacant"];
    bool has_entity = cell_json["has_entity"];
    nlohmann::json entity = cell_json["entity"];

    Entity *new_entity = nullptr;
    Cell* new_cell = nullptr;

    if (type == "Cell") {
        new_cell = new Cell(row, col, is_vacant);
    } else if (type == "Wall") {
        new_cell = new Wall(row, col);
    } else if (type == "EnterCell") {
        new_cell = new EnterCell(row, col, is_vacant);
    } else if (type == "ExitCell") {
        new_cell = new ExitCell(row, col, is_vacant);
    }

    if (has_entity)
    {
        new_entity = create_entity(row, col, entity);
        if (has_item)
        {
            new_cell->set_item(new_entity);
        }else
        {
            new_cell->set_creature(new_entity);
        }
    }
    return new_cell;
}

Entity *GameObjectsJsonCreator::create_entity(size_t row, size_t col, nlohmann::json& entity_json) {
    std::string entity_type = entity_json["type"];
    if (entity_type == "Player" || entity_type == "MageHealer" || entity_type == "ArcherSkeleton"
        || entity_type == "MeleeSkeleton")
    {
        return create_creature(row, col, entity_json);
    }
    else if (entity_type == "RestorationWand" || entity_type == "Bow")
    {
        return create_item(entity_json);
    }
    return nullptr;
}

Creature *GameObjectsJsonCreator::create_creature(size_t row, size_t col, nlohmann::json& entity_json) {
    std::string entity_type = entity_json["type"];
    int armor = entity_json["armor"];
    unsigned int curr_hp = entity_json["curr_hp"];
    unsigned int range = entity_json["attack_range"];
    unsigned int damage = entity_json["base_attack_damage"];
    unsigned int max_hp = entity_json["max_hp"];

    Creature* new_creature = nullptr;
    if (entity_type == "Player")
    {
        auto* new_player = new Player(max_hp,curr_hp,armor,damage, range);
        auto items = entity_json["items"];
        if (!items.is_null()) {
            for (auto item: items) {
                auto item_type = item["type"];
                if (item_type == "RestorationWand" || item_type == "Bow") {
                    Item* new_item = create_item(item);
                    new_player->add_item(new_item);
                }
            }
        }
        created_player = new_player;
        new_creature = new_player;
        player_col = col;
        player_row = row;
    }
    else if (entity_type == "ArcherSkeleton")
    {
        Enemy* new_enemy = new ArcherSkeleton(max_hp, curr_hp,armor,damage,range);
        enemies[new_enemy] = {row, col};
        enemies_num++;
        new_creature = new_enemy;
    }
    else if (entity_type == "MeleeSkeleton")
    {
        Enemy* new_enemy = new MeleeSkeleton(max_hp, curr_hp, armor, damage, range);
        enemies[new_enemy] = {row, col};
        enemies_num++;
        new_creature = new_enemy;
    }
    else if (entity_type == "MageHealer")
    {
        Enemy* new_enemy = new MageHealer(max_hp, curr_hp, armor, damage, range);
        enemies[new_enemy] = {row, col};
        enemies_num++;
        new_creature = new_enemy;
    }
    return new_creature;
}

Item *GameObjectsJsonCreator::create_item(nlohmann::json& entity_json) {
    std::string item_type = entity_json["type"];
    Item* new_item = nullptr;

    unsigned int range = entity_json["range"];
    unsigned int usages = entity_json["usages"];
    if (item_type == "Bow")
    {
        unsigned int damage = entity_json["damage"];
        new_item = new Bow(range, damage, usages);
    }
    else if (item_type == "RestorationWand") {
        unsigned int heal_power = entity_json["heal_power"];
        new_item = new RestorationWand(heal_power, usages);
    }
    return new_item;
}