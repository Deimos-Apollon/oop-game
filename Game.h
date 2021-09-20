//
// Created by deimos on 19.09.2021.
//

#ifndef OOP_GAME_GAME_H
#define OOP_GAME_GAME_H

#include "field/Field.h"

class Game {
    Field* field;
public:
    Game(){ field = new Field(10, 20); };
};


#endif //OOP_GAME_GAME_H
