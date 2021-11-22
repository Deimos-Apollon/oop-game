cmake_minimum_required(VERSION 3.20)
project(oop_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_game
        main.cpp Game/Game/Game.h Game/Game/Game.cpp
        field/Field/Field.h field/Field/Field.cpp
        field/Cells/Cell/Cell.h field/Cells/Cell/Cell.cpp field/Cells/EnterCell/EnterCell.h field/Cells/EnterCell/EnterCell.cpp
        field/Cells/ExitCell/ExitCell.cpp field/Cells/ExitCell/ExitCell.h CLI_Interface/CLI_Field/FieldView.cpp
        CLI_Interface/CLI_Field/FieldView.h entities/Creatures/Player/Player.cpp
        entities/Creatures/Player/Player.h
        entities/Creatures/Creature/Creature.cpp entities/Creatures/Creature/Creature.h field/FieldIterator/FieldIterator.cpp
        field/FieldIterator/FieldIterator.h CLI_Interface/CLI_Printable/CLI_Printable.cpp CLI_Interface/CLI_Printable/CLI_Printable.h
        field/Cells/Wall/Wall.h field/Cells/Wall/Wall.cpp entities/Creatures/Enemies/Enemy/Enemy.cpp
        entities/Creatures/Enemies/Enemy/Enemy.h entities/Items/Item/Item.cpp entities/Items/Item/Item.h
        entities/Creatures/Player/PlayerController/PlayerController.cpp
        entities/Creatures/Player/PlayerController/PlayerController.h entities/Creatures/Enemies/AIStrategy/AIStrategy.cpp
        entities/Creatures/Enemies/AIStrategy/AIStrategy.h entities/Creatures/Enemies/AIStrategy/ApproachStrategy/ApproachStrategy.cpp
        entities/Creatures/Enemies/AIStrategy/ApproachStrategy/ApproachStrategy.h entities/Items/MeleeDamageItems/Axe/Axe.cpp entities/Items/MeleeDamageItems/Axe/Axe.h
        entities/Items/MeleeDamageItems/MeleeDamageItem.cpp entities/Items/MeleeDamageItems/MeleeDamageItem.h entities/Creatures/Enemies/Enemies_types/MeleeSkeleton/MeleeSkeleton.cpp
        entities/Creatures/Enemies/Enemies_types/MeleeSkeleton/MeleeSkeleton.h ClassesHelpers/Randomer.cpp ClassesHelpers/Randomer.h entities/Entity/Entity.cpp entities/Entity/Entity.h
        field/FieldBuilder/FieldBuilder.cpp field/FieldBuilder/FieldBuilder.h field/FieldInterface/FieldInterface.cpp field/FieldInterface/FieldInterface.h
        entities/Items/HealItems/RestorationWand.cpp entities/Items/HealItems/RestorationWand.h entities/Creatures/Enemies/AIStrategy/MeleeSkeletonAgressiveStrategy/MeleeSkeletonAgressiveStrategy.cpp
        entities/Creatures/Enemies/AIStrategy/MeleeSkeletonAgressiveStrategy/MeleeSkeletonAgressiveStrategy.h entities/Creatures/Enemies/Enemies_types/ArcherSkeleton/ArcherSkeleton.cpp
        entities/Creatures/Enemies/Enemies_types/ArcherSkeleton/ArcherSkeleton.h entities/Creatures/Enemies/AIStrategy/ArcherSkeletonStrategy/ArcherSkeletonStrategy.cpp
        entities/Creatures/Enemies/AIStrategy/ArcherSkeletonStrategy/ArcherSkeletonStrategy.h entities/Creatures/Enemies/Enemies_types/MageHealer/MageHealer.cpp
        entities/Creatures/Enemies/Enemies_types/MageHealer/MageHealer.h entities/Creatures/Enemies/AIStrategy/MageHealerStrategy/MageHealerStrategy.cpp
        entities/Creatures/Enemies/AIStrategy/MageHealerStrategy/MageHealerStrategy.h entities/Items/Bow/Bow.cpp entities/Items/Bow/Bow.h
        entities/Creatures/Enemies/AIStrategy/StrategiesManager/StrategiesManager.cpp entities/Creatures/Enemies/AIStrategy/StrategiesManager/StrategiesManager.h
        Game/Logs/Logger/Logger.cpp Game/Logs/Logger/Logger.h Game/Logs/Adapter/Adapter.cpp Game/Logs/Adapter/Adapter.h Game/Logs/LogStream/FileStream/FileStream.cpp
        Game/Logs/LogStream/FileStream/FileStream.h Game/Logs/LogStream/ConsoleStream/ConsoleStream.cpp Game/Logs/LogStream/ConsoleStream/ConsoleStream.h
        Game/Logs/LogStream/LogStreamInterface.h Game/Logs/Observer/Observer.cpp Game/Logs/Observer/Observer.h Game/GameRules/AllEnemiesDeadRules.cpp
        Game/GameRules/AllEnemiesDeadRules.h)
