//
// Created by Deimos on 13.10.2021.
//

#ifndef OOP_GAME_MELEESKELETON_H

#include "Enemy/Enemy.h"

#define OOP_GAME_MELEESKELETON_H



class MeleeSkeleton : public Enemy {
public:
    MeleeSkeleton();
    MeleeSkeleton(Field* field, Cell* cell);
};


#endif //OOP_GAME_MELEESKELETON_H
