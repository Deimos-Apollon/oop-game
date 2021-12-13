//
// Created by deimos on 03.11.2021.
//

#include "Logger.h"



void Logger::print_console(const Entity *ent) {
    if (console != nullptr)
        console->write(ent);
}

void Logger::print_file(const Entity *ent) {
    for (auto file: files) {
        if (file != nullptr) {
            file->write(ent);
        }
    }
}

void Logger::set_logging_to_console() {
    console = new ConsoleStream();
}

void Logger::set_logging_to_file(const std::string& filename) {
    auto file = new FileStream(filename);
    files.push_back(file);
}

void Logger::reset_logging_to_file(FileStream* del_filestream) {
    /*auto del_find = std::find(files.begin(), files.end(), del_filestream);
    if (del_find != files.end()) {
        std::vector<FileStream>
        delete del_find;
        file = nullptr;
        using_file = false;
    } */
}

void Logger::reset_logging_to_console(ConsoleStream* del_consolestream) {
    delete console;
    console = nullptr;
}


void Logger::add_subscriber(Entity *ent) {
    if (ent != nullptr) {
        observer.add_object(ent);
    }
}

void Logger::remove_subscriber(Entity *ent) {
    if (ent != nullptr) {
        /* auto elem = std::find(observing_objects.begin(), observing_objects.end(), ent);
        if (elem != observing_objects.end()) {
            observing_objects.erase(elem);
            observer.remove_object(*elem);
        } */
    }
}

void Logger::proceed() {
    auto data = observer.check_objects();
    write_file(data);
    write_file("hello");
    write_console(data);
}

void Logger::write_console(const string &data) {
    if (console != nullptr)
        console->write(data);
}

void Logger::write_file(const string &data) {
    for (auto file: files) {
        if (file != nullptr)
            file->write(data);
    }
}


