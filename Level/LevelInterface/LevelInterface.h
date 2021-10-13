//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_LEVELINTERFACE_H
#include "../../entities/Creatures/Player/Player.h"
#include "../../field/Field.h"

#define OOP_GAME_LEVELINTERFACE_H



class LevelInterface {
protected:
    virtual void finish() {};
    virtual void proceed() {};
public:
    virtual void start() {};
};


#endif //OOP_GAME_LEVELINTERFACE_H
