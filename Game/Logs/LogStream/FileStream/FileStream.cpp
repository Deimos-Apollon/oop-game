//
// Created by Deimos on 07.11.2021.
//

#include "FileStream.h"


FileStream::FileStream(const std::string& filename) : file(filename) {
    if (!file.is_open())
    {
        throw std::runtime_error("file open failure");
    }
}

FileStream::~FileStream() {
    file.close();
}

void FileStream::write(const Entity *object) {
    s_stream << object;
    this->write(s_stream.str());
}

void FileStream::write(const string &data) {
    if (!file.eof())
    {
        file << data;
    } else
    {
        throw std::runtime_error("file write failure");
    }
}



