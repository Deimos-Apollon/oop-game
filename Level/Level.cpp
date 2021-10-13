//
// Created by Deimos on 12.10.2021.
//
#include "Level.h"


Level::Level(Player *player, Field *field, vector<Enemy*> enemies, unsigned int enemies_num, vector <Item*> items) :
        player(player), field(field), enemies(std::move(enemies)), enemies_num(enemies_num), items(std::move(items)){

}

void Level::start() {
    player->set_cell(field->get_enter_cell());
    field->get_enter_cell()->set_entity(player);

    // add two enemies
    auto enemy = new Enemy(field,field->get_cell_non_const(3, 4),20,0,5);
    enemies.push_back(enemy);
    field->get_cell_non_const(3, 4)->set_entity(enemies[0]);

    auto enemy2 = new Enemy(field,field->get_cell_non_const(5, 5),20,0,5);
    enemies.push_back(enemy2);
    field->get_cell_non_const(5, 5)->set_entity(enemies[1]);

    enemies_num = 2;

    // add Axe
    Axe* axe = new Axe(field->get_cell_non_const(6, 6), 3, 10);
    field->get_cell_non_const(6,6)->set_entity(axe);
    field->get_cell_non_const(6,6)->set_has_item(true);
    items.push_back(axe);

    this->proceed();
}

void Level::proceed() {
    bool go = true;
    auto row_exit = field->get_exit_cell()->get_row();
    auto col_exit = field->get_exit_cell()->get_col();

    auto* approach_strategy = new ApproachStrategy();
    enemies[0]->set_strategy(approach_strategy);
    enemies[1]->set_strategy(approach_strategy);

    int game_ticks = 0;     //TODO delete
    while (go)
    {
        std::system("cls");
        lw->print();
        std::cout << "Your hp: " << player->get_hp();
        auto row = player->get_row();
        auto col = player->get_col();
        if (row == row_exit && col == col_exit)
        {
            this->finish();
            break;
        }
        if (player->get_hp() == 0) {
            std::cout << "you lose!\n" << game_ticks;  // TODO VERY BAD
            system("pause");
            this->finish();
            break;
        }
        if(_kbhit()) {
            auto key = _getch();
            switch (key) {
                case 72:        // up
                    player->move(field->get_cell_non_const(row - 1, col));
                    break;
                case 80:        //down
                    player->move(field->get_cell_non_const(row + 1, col));
                    break;
                case 75:        //left
                    player->move(field->get_cell_non_const(row, col - 1));
                    break;
                case 77:        //right
                    player->move(field->get_cell_non_const(row, col + 1));
                    break;
                case 32:
                    if (enemies_num != 0) {
                        player->attack(enemies[0]);         // TODO VERY BAD
                    }
                    break;
                default:
                    break;
            }
        }
        for (auto enemy: enemies)
        {
            enemy->get_strategy()->step(enemy, player);
            game_ticks += 1;
        }
        for (int i = 0; i < enemies_num; ++i)
        {
            if (enemies[i]->get_hp() == 0)
            {
                auto tmp = enemies[i];
                enemies.erase(enemies.begin() + i);
                delete tmp;
                --i;
                --enemies_num;
            }
            game_ticks += 1;
        }
        _sleep(300);
    }
    this->finish();
}

void Level::finish() {

}
