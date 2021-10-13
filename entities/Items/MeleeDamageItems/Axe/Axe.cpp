//
// Created by Deimos on 13.10.2021.
//

#include "Axe.h"

Axe::Axe(unsigned int range, unsigned int damage) : MeleeDamageItem(range, damage){

}

Axe::Axe(Cell *cell, unsigned int range, unsigned int damage) : MeleeDamageItem(cell, range, damage) {

}
