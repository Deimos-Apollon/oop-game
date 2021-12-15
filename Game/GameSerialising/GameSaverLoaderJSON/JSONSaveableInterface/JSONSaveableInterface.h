//
// Created by deimos on 14.12.2021.
//

#ifndef OOP_GAME_JSONSAVEABLEINTERFACE_H
#define OOP_GAME_JSONSAVEABLEINTERFACE_H

#include "/home/deimos/CLionProjects/oop-game/external_libraries/json.hpp"

class JSONSaveableInterface{
public:
    virtual nlohmann::json get_json_repr() const = 0;
};


#endif //OOP_GAME_JSONSAVEABLEINTERFACE_H
