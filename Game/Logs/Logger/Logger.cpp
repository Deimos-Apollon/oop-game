//
// Created by deimos on 03.11.2021.
//

#include "Logger.h"


void Logger::print(const Entity *ent) {
    if (ent != nullptr) {
        print_console(ent);
        print_file(ent);
    }
}

void Logger::print_console(const Entity *ent) {
    if (using_console)
        console->write(ent);

}

void Logger::print_file(const Entity *ent) {
    if (using_file)
        file->write(ent);
}

void Logger::set_logging_to_console() {
    console = new ConsoleStream();
    using_console = true;
}

void Logger::set_logging_to_file(const std::string& filename) {
    file = new FileStream(filename);
    using_file = true;
}

void Logger::reset_logging_to_file() {
    delete file;
    file = nullptr;
    using_file = false;
}

void Logger::reset_logging_to_console() {
    delete console;
    console = nullptr;
    using_console = false;
}


void Logger::add_subscriber(Entity *ent) {
    if (ent != nullptr) {
        observing_objects.push_back(ent);
        observer.add_object(ent);
    }
}

void Logger::remove_subscriber(Entity *ent) {
    if (ent != nullptr) {
        auto elem = std::find(observing_objects.begin(), observing_objects.end(), ent);
        if (elem != observing_objects.end())
            observing_objects.erase(elem);
    }
}

void Logger::proceed_subscribers() {
    for (auto object: observing_objects)
    {
        auto data = observer.check_object(object);
        write_file(data);
        write_console(data);
    }
}

void Logger::write_console(const string &data) {
    if (using_console)
        console->write(data);
}

void Logger::write_file(const string &data) {
    if (using_file)
        file->write(data);
}


