//
// Created by Deimos on 07.11.2021.
//

#ifndef OOP_GAME_CONSOLESTREAM_H
#define OOP_GAME_CONSOLESTREAM_H

#include <iostream>
#include "../LogStreamInterface.h"

class ConsoleStream : public LogStreamInterface{
public:
    void write(const std::string &data) override;
   void write(const Entity *object) override;
};


#endif //OOP_GAME_CONSOLESTREAM_H
