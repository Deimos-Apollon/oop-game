//
// Created by deimos on 14.12.2021.
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include "GameSaverLoaderJSON.h"


void GameSaverLoaderJSON::load_game(const string &filename, const vector<FieldInterface *> &field) {

}

void GameSaverLoaderJSON::save_game(const string &filename, JSONSaveableInterface *save_objects) {
    std::ofstream file(filename);
    if (file.is_open())
    {
        json json_info = {};
        json_info.push_back(save_objects->get_json_repr());
        file << std::setw(4) << json_info << std::endl;
    } else
        std::cout << "error opening file\n";
    file.close();
}
