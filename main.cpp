//
// Created by deimos on 19.09.2021.
//
#include "Game.h"
#include "CLI_Interface/field_interface/FieldView.h"

int main()
{
//    std::cout << "5x1:\n";
//    Field field(5, 1);
//    std::cout << "2x1:\n";
//    Field field2(2, 1);
//    std::cout << "1x2:\n";
//    Field field3(1, 2);

      Field field4(20, 50, 50);
      FieldView fw(field4);
      fw.print();
}