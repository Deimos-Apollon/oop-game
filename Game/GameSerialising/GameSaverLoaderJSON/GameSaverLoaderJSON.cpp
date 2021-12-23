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

        try {
            json data_json;
            file >> data_json;
            json field_json = data_json["field"];

            valid = gameObjectsJsonCreator.create_data(field_json);
        } catch (const nlohmann::detail::type_error& e)
        {
            valid = false;
        }
        catch (const nlohmann::detail::parse_error& e)
        {
            valid = false;
        }
    }
    file.close();
    if (valid) {
        delete field;

        field = gameObjectsJsonCreator.get_field();

        player = gameObjectsJsonCreator.get_player();
        gameObjectsJsonCreator.refresh();
    }

    return valid;
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