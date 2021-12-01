//
// Created by deimos on 19.09.2021.
//


#include "GameMenu/GameMenu.h"

int main() {

    // TODO исправить на size_t, создать Level, который будет хранить правила и поле, и передавать туда тапл классов игры
    //GameMenu gameMenu;
    FieldInterface* field{};
    auto new_f = dynamic_cast<Field*>(field);
    new_f->start();
}