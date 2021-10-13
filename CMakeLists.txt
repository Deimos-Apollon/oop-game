cmake_minimum_required(VERSION 3.20)
project(oop_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_game
        main.cpp Game/Game.h Game/Game.cpp
        field/Field.h field/Field.cpp
        field/Cells/Cell.h field/Cells/Cell.cpp field/Cells/EnterCell.h field/Cells/EnterCell.cpp
        field/Cells/ExitCell.cpp field/Cells/ExitCell.h CLI_Interface/field_interface/FieldView.cpp
        CLI_Interface/field_interface/FieldView.h entities/Creatures/Player/Player.cpp
        entities/Creatures/Player/Player.h entities/Entity.cpp entities/Entity.h
        entities/Creatures/Creature.cpp entities/Creatures/Creature.h field/FieldIterator.cpp
        field/FieldIterator.h CLI_Interface/CLI_Printable.cpp CLI_Interface/CLI_Printable.h
        field/Cells/Wall.h field/Cells/Wall.cpp entities/Creatures/Enemies/Enemy/Enemy.cpp
        entities/Creatures/Enemies/Enemy/Enemy.h entities/Items/Item.cpp entities/Items/Item.h
        Level/Level.cpp Level/Level.h Level/LevelInterface/LevelInterface.cpp Level/LevelInterface/LevelInterface.h
        CLI_Interface/level_interface/LevelView.cpp CLI_Interface/level_interface/LevelView.h Game/GameInterface.cpp
        Game/GameInterface.h classes-interfacesd/PlayerController/PlayerController.cpp
        classes-interfacesd/PlayerController/PlayerController.h classes-interfacesd/AIStrategy/AIStrategy.cpp
        classes-interfacesd/AIStrategy/AIStrategy.h classes-interfacesd/AIStrategy/ApproachStrategy/ApproachStrategy.cpp
        classes-interfacesd/AIStrategy/ApproachStrategy/ApproachStrategy.h entities/Items/MeleeDamageItems/Axe/Axe.cpp entities/Items/MeleeDamageItems/Axe/Axe.h entities/Items/MeleeDamageItems/MeleeDamageItem.cpp entities/Items/MeleeDamageItems/MeleeDamageItem.h entities/Creatures/Enemies/MeleeSkeleton.cpp entities/Creatures/Enemies/MeleeSkeleton.h Level/Level_Builder/LevelBuilder.cpp Level/Level_Builder/LevelBuilder.h)
