//
// Created by Deimos on 16.10.2021.
//

#ifndef OOP_GAME_ENTITY_H
#define OOP_GAME_ENTITY_H


#include "../../Game/GameSerialising/GameSaverLoaderJSON/JSONSaveableInterface/JSONSaveableInterface.h"

class Entity : JSONSaveableInterface{
    mutable bool changed = false;

public:
    virtual ~Entity() = default;
    bool get_and_restore_has_changed() const;
    void set_has_changed(bool new_value) { changed = new_value; }
    nlohmann::json get_json_repr() const override = 0;
};

#endif //OOP_GAME_ENTITY_H
