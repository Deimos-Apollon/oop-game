//
// Created by Deimos on 16.10.2021.
//

#ifndef OOP_GAME_ENTITY_H
#define OOP_GAME_ENTITY_H


class Entity {
    mutable bool changed = false;

public:
    virtual ~Entity() = default;
    bool get_and_restore_has_changed() const;
    void set_has_changed(bool new_value) { changed = new_value; }
};

#endif //OOP_GAME_ENTITY_H
