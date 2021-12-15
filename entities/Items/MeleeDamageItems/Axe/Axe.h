//
// Created by Deimos on 13.10.2021.
//ё

#ifndef OOP_GAME_AXE_H

#include "../MeleeDamageItem.h"

#define OOP_GAME_AXE_H


class Axe : public MeleeDamageItem{
public:
    explicit Axe(unsigned int range=1, unsigned int damage=10, unsigned int usages=50);
    nlohmann::json get_json_repr() const override;
};


#endif //OOP_GAME_AXE_H
