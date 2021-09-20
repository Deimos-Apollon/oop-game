cmake_minimum_required(VERSION 3.20)
project(oop_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_game
        main.cpp Game.h
        field/Field.h field/Field.cpp
        field/Cells/Cell.h field/Cells/Cell.cpp field/Cells/EnterCell.h field/Cells/EnterCell.cpp
        field/Cells/ExitCell.cpp field/Cells/ExitCell.h)
