//
// Created by deimos on 19.09.2021.
//

#include "Game.h"


Game::Game(Player *player, LevelInterface **levels, unsigned int levels_num) :
            player(player), levels(levels), levels_num(levels_num){

}

void Game::proceed() {
    LevelInterface* curr_level;
    for (unsigned int i = 0; i < levels_num; ++i)
    {
        curr_level = levels[i];
        curr_level->start();
    }
}

void Game::finish() {

}

void Game::start() {
    if (player == nullptr)
    {
        player = new Player(50,2,10);
    }
    if (levels == nullptr)  // TODO delete, this is just demonstration
    {
        levels = new LevelInterface*[2];
        Field* field0 = new Field(8, 8, 0);
        levels[0] = new Level(player, field0);
        Field* field1 = new Field(20, 20, 30);
        levels[1] = new Level(player, field1);
        levels_num = 2;
    }
    this->proceed();
}
