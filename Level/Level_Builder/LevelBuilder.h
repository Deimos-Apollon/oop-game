//
// Created by Deimos on 13.10.2021.
//

#ifndef OOP_GAME_LEVELBUILDER_H
#include "../Level.h"
#define OOP_GAME_LEVELBUILDER_H


class LevelBuilder {
    Player* player = nullptr;
    Field* field = nullptr;
    vector <Enemy*> enemies = {};
    vector <Item*> items = {};
    unsigned int enemies_num = 0;
    FieldIterator* fi = new FieldIterator(*field); // TODO delete
    LevelView* lw = new LevelView(*fi); // TODO delete
public:
    void create_field(unsigned int rows, unsigned int cols, unsigned  int walls_percentage=50);

};


#endif //OOP_GAME_LEVELBUILDER_H
