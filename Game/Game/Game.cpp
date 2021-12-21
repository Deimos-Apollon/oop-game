//
// Created by deimos on 19.09.2021.
//

#include "Game.h"
#include <utility>



template<class ... Rules>
Game<Rules...>::Game(Player *player, std::vector<FieldInterface*> fields, unsigned int fields_num) :
            player(player), fields(std::move(fields)), fields_num(fields_num){

}


template<class ... Rules>
void Game<Rules...>::proceed() {
    FieldInterface* curr_level;

    bool need_to_load_new = false;
    for (std::size_t i = 0; i < fields_num; ++i)
    {
        if (need_to_load_new) break;

        curr_level = fields[i];
        player_controller->set_field(curr_level, need_to_load_new);

        curr_level->set_logger(&logger);
        FieldIterator fi(*dynamic_cast<Field *>(curr_level));
        FieldView lv(fi);

        curr_level->start();
        bool level_stop = false;
        field_prev_number = curr_level->get_number();
        while(!level_stop)
        {
            lv.print();
            curr_level->proceed();
            player_controller->proceed();
            if (need_to_load_new)
            {
                current_field = curr_level->get_number();
                break;
            }
            if (curr_level->player_stands_on_exit()) {
                switch (i)                                   // TODO DELETE VERY BAD
                {
                    case 0:
                        level_stop = (std::get<0>(levels_rules)).tasks_complited();
                        break;
                    case 1:
                        level_stop = (std::get<1>(levels_rules)).tasks_complited();
                        break;
                }
            }

            if (player->get_curr_hp() == 0)
            {
                this->finish();
            }

            std::system("clear");

        };
    }
    if (need_to_load_new) this->reload();
    else this->finish();
}

template<class ... Rules>
void Game<Rules...>::finish() {
    if (player->get_curr_hp() != 0)
    {
        std::cout << "Поздравляем, игра пройдена!!!\n";
    }  else
    {
        std::cout << "YOU DIED\n";
    }
}


template<class ... Rules>
void Game<Rules...>::start() {
    logger.set_logging_to_console();
    logger.set_logging_to_file(R"(C:\Users\Deimos\CLionProjects\oop-game\LOG_FILES\Logs_file.txt)");

    this->levels_init();

    this->proceed();
}

template<class... Rules>
Game<Rules...>::~Game() {
    for (size_t i = 0; i < fields_num; ++i)
    {
        delete fields[i];
    }

    delete player;
    player = nullptr;

}

template<class... Rules>
Game<Rules...>::Game(Player *player, FieldInterface *field_to_load, size_t field_num):
player(player)
{
    fields.push_back(field_to_load);
    ++fields_num;
    current_field = field_num;
    // TODO FIELD_NUM
}

template<class... Rules>
void Game<Rules...>::levels_init() {

    if (player == nullptr)
    {
        player = new Player(50,2,5);
    }
    logger.add_subscriber(player);
    FieldBuilder fb;

    if (fields.empty()) {

        fb.create_cells(8, 8);
        fb.add_player(player);
        fb.add_RestorationWand();
        fb.add_Bow();
        fb.set_number(0);
        //fb.add_enemy_MeleeSkeleton();
        //fb.add_enemy_ArcherSkeleton();
        //fb.add_enemy_MageHealer();

        Field *field = fb.get_result();
        fields.push_back(field);
        fields_num++;
    }
    if (field_prev_number == 0 && current_field == 0){
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
        fb.set_number(1);
        Field *field1 = fb.get_result();

        fields.push_back(field1);
        fields_num++;
    }


    if (current_field == 0 and field_prev_number == 0)
    {
        // nothing
    }
    else if (current_field == 0 and field_prev_number == 1)
    {
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
        fb.set_number(1);
        Field *field1 = fb.get_result();

        delete fields[0];
        fields[0] = fields[1];
        fields[1] = field1;
    }
    else if (current_field == 1 and field_prev_number == 0)
    {
        if(fields_num == 2) {
            fields.erase(std::next(fields.begin()));
            fields_num--;
        }
    }
    else // cur = 1 and prev = 1
    {
        if (fields_num == 2) {
            delete fields[0];
            fields.erase(fields.begin());
        }
    }
    if (fields_num == 1)

    for (std::size_t i = 0; i < fields_num; ++i)
    {

        switch(i)                                   // TODO DELETE VERY BAD IT IS INIT
        {
            case 0:
                std::get<0>(levels_rules).set_field(fields[i]);
                break;
            case 1:
                std::get<1>(levels_rules).set_field(fields[i]);
                break;
            default:
                break;
        }
    }
    player_controller->set_player(player);
}

template<class... Rules>
void Game<Rules...>::reload() {
    this->levels_init();
    logger.remove_all();
    this->proceed();
}
