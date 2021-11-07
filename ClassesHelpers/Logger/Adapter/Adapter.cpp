//
// Created by deimos on 03.11.2021.
//

#include "Adapter.h"

string Adapter::player_info(Player &player) {
    std::string text =
            "\nPlayer info: "
            "\nHealth: " + to_string(player.get_curr_hp()) + "/" + to_string(player.get_max_hp()) +
            "\nArmor: " + to_string(player.get_armor()) +
            "\nAttackDamage: " + to_string(player.get_basic_attack_damage()) +
            "\nAttackRange: " + to_string(player.get_attack_range());
    bool has_item = player.get_using_item();
    text += "\nHas item?: " + to_string(has_item);
    return text;
}

string Adapter::enemy_info(Enemy &enemy) {
    std::string text =
            "\nEnemy info: "
            "\nHealth: " + to_string(enemy.get_curr_hp()) + "/" + to_string(enemy.get_max_hp()) +
            "\nArmor: " + to_string(enemy.get_armor()) +
            "\nAttackDamage: " + to_string(enemy.get_basic_attack_damage()) +
            "\nAttackRange: " + to_string(enemy.get_attack_range());
    return text;
}

string Adapter::item_info(Item &item) {
    std::string text =
            "\nItem info"
            "\nIs damaging: " + to_string(item.is_damaging()) +
            "\nUsages" + to_string(item.get_usages()) +
            "\nRange" + to_string(item.get_range());
    return text;
}
