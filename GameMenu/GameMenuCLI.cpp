//
// Created by deimos on 01.12.2021.
//

#include "GameMenuCLI.h"


void GameMenuCLI::run() {

    bool loop_go = true;
    while(loop_go)
    {
        if (window == MAIN_MENU)
        {
            char got_code;
            game_menu_view.print();
            std::cin >> got_code;

            switch(got_code) {
                case '1':
                    this->game_init();
                    game.start();
                    /*
                     while (game.was_load_new())
                     {
                        game = game.load_new();
                        game.start()
                     }
                     */
                    loop_go = false;
                    break;
                case '2':
                    window = SETTING;
                    break;
                case '3':
                    loop_go = false;
                    break;
            }
        }else if (window == SETTING)
        {
            game_menu_view.print_curr_settings(settings_CLI);
            std::cout << "Если хотите изменить настройки - введите клавишу, которую хотите поменять, или -1 "
                         "для выхода\n";
            int got_code;
            std::cin >> got_code;
            if (got_code == -1)
            {
                window = MAIN_MENU;
            }
            else {
                auto curr_settings = settings_CLI.get_curr_settings();
                if (curr_settings.find(static_cast<Commands>(got_code)) != curr_settings.end())
                {
                    char new_key;
                    std::cout << "Введите новый ключ: \n";
                    std::cin >> new_key;
                    settings_CLI.change_key(static_cast<Commands>(got_code), new_key);
                } else
                {
                    std::cout << "Нет настройки с таким номером!\n";
                }
            }
        }

    }
}

void GameMenuCLI::game_init() {
    player_controller = PlayerControllerCLI(settings_CLI.get_curr_settings());
    game.setPlayerController(&player_controller);
}
