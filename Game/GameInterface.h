//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_GAMEINTERFACE_H
#define OOP_GAME_GAMEINTERFACE_H


class GameInterface {
protected:
    virtual void proceed() {};
    virtual void finish() {};
public:
    virtual void start() {};
};


#endif //OOP_GAME_GAMEINTERFACE_H
