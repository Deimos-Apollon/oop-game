//
// Created by deimos on 19.09.2021.
//

#include "Game.h"
#include "../../CLI_Interface/CLI_Field/FieldView.h"


Game::Game(Player *player, FieldInterface **fields, unsigned int fields_num) :
            player(player), fields(fields), fields_num(fields_num){

}

void Game::proceed() {
    FieldInterface* curr_level;

    for (unsigned int i = 0; i < fields_num; ++i)
    {
        curr_level = fields[i];

        FieldIterator fi(*dynamic_cast<Field *>(curr_level));
        FieldView lv(fi);

        curr_level->start();
        bool level_go;

        do
        {
            lv.print();
            level_go = curr_level->proceed();
            system("cls");
        } while (level_go);
    }
}

void Game::finish() {

}

void Game::start() {
    logger.set_logging_to_console();

    logger.set_logging_to_file(R"(C:\Users\Deimos\CLionProjects\oop-game\LOG_FILES\Logs_file.txt)");

    if (player == nullptr)
    {
        player = new Player(50,2,5);
        logger.add_subscriber(player);
    }
    if (fields == nullptr)  // TODO delete, this is just demonstration
    {
        fields = new FieldInterface*[2];

        FieldBuilder fb(logger);
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
