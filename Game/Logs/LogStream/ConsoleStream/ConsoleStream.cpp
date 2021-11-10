//
// Created by Deimos on 07.11.2021.
//


#include "ConsoleStream.h"

void ConsoleStream::write(const Entity *object) {
    std::cout << object;
}

void ConsoleStream::write(const string &data) {
    std::cout << data;
}
