//
// Created by deimos on 20.09.2021.
//

#ifndef OOP_GAME_WALL_H
#define OOP_GAME_WALL_H


class Wall : public Cell{
public:
    Wall(unsigned x, unsigned y): Cell(x, y, false){};
    ~Wall() override = default;
};


#endif //OOP_GAME_WALL_H
