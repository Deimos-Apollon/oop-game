//
// Created by deimos on 14.12.2021.
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include "GameSaverLoaderJSON.h"


void GameSaverLoaderJSON::load_game(const vector<FieldInterface *> &field, const string &filename) {

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
