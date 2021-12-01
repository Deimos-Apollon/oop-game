//
// Created by deimos on 01.12.2021.
//

#include "GameMenu.h"


void GameMenu::run() {
    char got_code;
    bool loop_go = true;
    while(loop_go)
    {
        if (window == MAIN_MENU)
        {
            game_menu_view.print();
            std::cin >> got_code;

            switch(got_code) {
                case '1':
                    player_controller = PlayerControllerCLI(settings_CLI.get_key_bounds());
                    game.setPlayerController(&player_controller);
                    game.start();
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
            std::cout << "Если хотите изменить настройки - введите клавишу, которую хотите поменять, или ` "
                         "для выхода\n";
            std::cin >> got_code;
            if (got_code == '`')
            {
                window = MAIN_MENU;
            }
            else {
                auto curr_settings = settings_CLI.get_key_bounds();
                if (curr_settings.find(got_code) != curr_settings.end()) {
                    char new_key;
                    std::cout << "Введите новый ключ: \n";
                    std::cin >> new_key;
                    settings_CLI.change_key(curr_settings[got_code], new_key);
                }
            }
        }

    }
}
