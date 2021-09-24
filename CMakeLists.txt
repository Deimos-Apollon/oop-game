cmake_minimum_required(VERSION 3.20)
project(oop_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_game
        main.cpp Game.h
        field/Field.h field/Field.cpp
        field/Cells/Cell.h field/Cells/Cell.cpp field/Cells/EnterCell.h field/Cells/EnterCell.cpp
        field/Cells/ExitCell.cpp field/Cells/ExitCell.h CLI_Interface/field_interface/FieldView.cpp CLI_Interface/field_interface/FieldView.h entities/Creatures/Player/Player.cpp entities/Creatures/Player/Player.h entities/Entity.cpp entities/Entity.h entities/Creatures/Creature.cpp entities/Creatures/Creature.h field/FieldIterator.cpp field/FieldIterator.h CLI_Interface/CLI_Printable.cpp CLI_Interface/CLI_Printable.h)
