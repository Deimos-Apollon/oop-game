//
// Created by Deimos on 07.11.2021.
//

#ifndef OOP_GAME_FILE_H

#include <fstream>
#include <string>
#include <sstream>
#include "../LogStreamInterface.h"

#define OOP_GAME_FILE_H


class FileStream : public LogStreamInterface {
    std::ofstream file;
    stringstream s_stream;

public:
    explicit FileStream(const std::string& filename);
    ~FileStream();

    void write(const std::string &data) override;
    void write(const Entity *object) override;
};


#endif //OOP_GAME_FILE_H
