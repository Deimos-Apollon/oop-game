//
// Created by deimos on 19.09.2021.
//

#include "Game.h"



Game::Game(Player *player, FieldInterface **fields, unsigned int fields_num) :
            player(player), fields(fields), fields_num(fields_num){

}

void Game::proceed() {
    FieldInterface* curr_level;
    for (unsigned int i = 0; i < fields_num; ++i)
    {
        curr_level = fields[i];
        curr_level->start();
    }
}

void Game::finish() {

}

void Game::start() {
    if (player == nullptr)
    {
        player = new Player(50,2,5);
    }
    if (fields == nullptr)  // TODO delete, this is just demonstration
    {
        fields = new FieldInterface*[2];

        FieldBuilder fb;
        fb.create_cells(8, 8);
        fb.add_player(player);
        fb.add_RestorationWand();
        fb.add_Bow();
        //fb.add_enemy_MeleeSkeleton();
        //fb.add_enemy_ArcherSkeleton();
        //fb.add_enemy_MageHealer();

        Field* field = fb.get_result();
        fields[0] = field;
        fields_num++;

        fb.create_cells(20, 30, 10);
        fb.add_player(player);
        fb.add_Axe();
        fb.add_enemy_MeleeSkeleton();
        fb.add_enemy_MeleeSkeleton();
        fb.add_enemy_MeleeSkeleton();
        fb.add_enemy_MeleeSkeleton();
        fb.add_enemy_MeleeSkeleton();
        fb.add_enemy_MeleeSkeleton();
        fb.add_enemy_ArcherSkeleton();
        fb.add_enemy_MageHealer();
        fb.add_enemy_MageHealer();
        Field* field1 = fb.get_result();
        fields[1] = field1;
        fields_num++;
    }
    this->proceed();
}

Game::~Game() {
    for (size_t i = 0; i < fields_num; ++i)
    {
        delete fields[i];
    }
    delete [] fields;
    fields = nullptr;

    delete player;
    player = nullptr;
}
