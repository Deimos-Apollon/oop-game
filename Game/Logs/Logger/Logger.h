//
// Created by deimos on 03.11.2021.
//

#ifndef OOP_GAME_LOGGER_H

#include <iostream>
#include "../LogStream/FileStream/FileStream.h"
#include "../LogStream/ConsoleStream/ConsoleStream.h"
#include "../Observer/Observer.h"

#include <vector>
#define OOP_GAME_LOGGER_H



using namespace std;
class Logger {
    std::vector <Entity*> observing_objects;           // TODO use set

    Observer observer;
    FileStream* file = nullptr;
    ConsoleStream* console = nullptr;
    bool using_console = false;
    bool using_file = false;
public:

    void print_console(const Entity* ent);
    void print_file(const Entity* ent);

    void write_console(const std::string& data);
    void write_file(const std::string& data);

    void set_logging_to_file(const std::string& filename);
    void set_logging_to_console();

    void reset_logging_to_file();
    void reset_logging_to_console();

    void add_subscriber(Entity* ent);
    void remove_subscriber(Entity* ent);
    void proceed_subscribers();
};


#endif //OOP_GAME_LOGGER_H
