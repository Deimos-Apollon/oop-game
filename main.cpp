//
// Created by deimos on 19.09.2021.
//
#include "Game.h"
#include "CLI_Interface/field_interface/FieldView.h"


int main() {
//    std::cout << "5x1:\n";
//    Field field(5, 1);
//    FieldView fw(field);
//    fw.print();
//    std::cout << "\n";
//    std::cout << "2x1:\n";
//    Field field2(2, 1);
//    FieldView fw2(field2);
//    fw2.print();
//    std::cout << "\n";
//    std::cout << "1x2:\n";
//    Field field3(1, 2);
//    FieldView fw3(field3);
//    fw3.print();
//    std::cout << "\n";
//    std::cout << "1x5:\n";
//    Field field15(1, 5);
//    FieldView fw15(field15);
//    fw15.print();
//    std::cout << "\n";
//    std::cout << "10x30:\n";
//    Field field4(10, 30);
//    FieldView fw4(field4);
//    fw4.print();
//    std::cout << "\n";
//
//    std::cout << "1x1:\n";
//    Field field11(1, 1);
//    FieldView fw11(field11);
//    fw11.print();

      // copy constructor
      Field field4(3, 10);
      Field field5(field4);
      FieldView fw4(field4);
      FieldView fw5(field5);
      fw4.print();
      std::cout<<"\ncopied:\n";
      fw5.print();

    // copy operator
    Field field6(3, 5);
    Field field7(3, 5);
    FieldView fw6(field6);
    FieldView fw7(field7);
    std::cout<<"\nCopying where\n";
    fw6.print();
    std::cout<<"\nCopying what\n";
    fw7.print();
    std::cout<<"\nAfter copy operator:\n";
    field6 = field7;
    fw6.print();
    std::cout << "\n";
    // move constructor
    Field field9(std::move(Field(3,4)));
    FieldView fw9(field9);
    std::cout << "After std::move\n";
    fw9.print();
    std::cout << "\n";
     //move operator
        Field field10(3, 6);
        FieldView fw10(field10);
        std::cout << "Before move\n";
        fw10.print();
        field10 = Field(5, 5);
        std::cout << "After move\n";
        fw10.print();
    std::cout << "\n";
}