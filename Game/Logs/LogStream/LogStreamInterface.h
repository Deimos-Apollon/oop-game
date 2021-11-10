//
// Created by Deimos on 07.11.2021.
//

#ifndef OOP_GAME_LOGSTREAMINTERFACE_H
#define OOP_GAME_LOGSTREAMINTERFACE_H

#include "../Adapter/Adapter.h"

class LogStreamInterface {
public:
    virtual void write(const std::string& data) = 0;
    virtual void write(const Entity* object) = 0;
};


#endif //OOP_GAME_LOGSTREAMINTERFACE_H
