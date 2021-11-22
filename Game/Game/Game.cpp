//
// Created by deimos on 19.09.2021.
//

#include "Game.h"
#include <utility>


template<class ... Rules>
Game<Rules...>::Game(Player *player, FieldInterface **fields, unsigned int fields_num) :
            player(player), fields(fields), fields_num(fields_num){

}


template<class ... Rules>
void Game<Rules...>::proceed() {
    FieldInterface* curr_level;

    for (std::size_t i = 0; i < fields_num; ++i)
    {
        curr_level = fields[i];

        FieldIterator fi(*dynamic_cast<Field *>(curr_level));
        FieldView lv(fi);

        curr_level->start();
        bool level_stop = false;

        while(!level_stop)
        {
            lv.print();
            curr_level->proceed();
            switch(i)                                   // TODO DELETE VERY BAD
            {
                case 0:
                    level_stop = (std::get<0>(levels_rules)).tasks_complited();
                    break;
                case 1:
                    level_stop = (std::get<1>(levels_rules)).tasks_complited();
                    break;
                default:
                    break;
            }
            system("cls");
        };
    }
}

template<class ... Rules>
void Game<Rules...>::finish() {

}


template<class ... Rules>
void Game<Rules...>::start() {
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

    for (std::size_t i = 0; i < fields_num; ++i)
    {
        switch(i)                                   // TODO DELETE VERY BAD IT IS INIT
        {
            case 0:
                std::get<0>(levels_rules).set_number(0);
                std::get<0>(levels_rules).set_field(fields[i]);
                break;
            case 1:
                std::get<1>(levels_rules).set_number(1);
                std::get<1>(levels_rules).set_field(fields[i]);
                break;
            default:
                break;
        }
    }

    this->proceed();
}

template<class... Rules>
Game<Rules...>::~Game() {
    for (size_t i = 0; i < fields_num; ++i)
    {
        delete fields[i];
    }
    delete [] fields;
    fields = nullptr;

    delete player;
    player = nullptr;
}




