//
// Created by deimos on 21.12.2021.
//

#ifndef OOP_GAME_GAMEOBJECTSJSONCREATOR_H
#define OOP_GAME_GAMEOBJECTSJSONCREATOR_H


#include "../../../field/Cells/Cell/Cell.h"
#include "../../../field/Cells/EnterCell/EnterCell.h"
#include "../../../field/Cells/ExitCell/ExitCell.h"
#include "../../../field/Cells/Wall/Wall.h"
#include "../../../entities/Creatures/Enemies/Enemy/Enemy.h"
#include "../../../entities/Creatures/Enemies/Enemies_types/MeleeSkeleton/MeleeSkeleton.h"
#include "../../../entities/Creatures/Enemies/Enemies_types/ArcherSkeleton/ArcherSkeleton.h"
#include "../../../entities/Creatures/Enemies/Enemies_types/MageHealer/MageHealer.h"
#include "../../../field/Field/Field.h"

class GameObjectsJsonCreator {
    Field* created_field = nullptr;
    Player* created_player = nullptr;

    map <Enemy*, pair<unsigned int, unsigned int>> enemies;
    unsigned int enemies_num = 0;
    unsigned int player_row = 0, player_col = 0;
private:
    Cell* create_cell(size_t row, size_t col, nlohmann::json& cell_json);

    Entity* create_entity(size_t row, size_t col, nlohmann::json& entity_json);

    Creature* create_creature(size_t row, size_t col, nlohmann::json& entity_json);

    Item* create_item(nlohmann::json& entity_json);

public:
    bool create_data(nlohmann::json& field_json);

    Player* get_player() {return created_player; }
    Field* get_field() { return created_field; }

    void refresh() {created_field = nullptr; created_player = nullptr; enemies.clear();
                    enemies_num = 0; player_col = 0; player_row = 0; }
};


#endif //OOP_GAME_GAMEOBJECTSJSONCREATOR_H
