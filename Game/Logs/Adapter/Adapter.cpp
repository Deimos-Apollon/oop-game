//
// Created by deimos on 03.11.2021.
//

#include "Adapter.h"


Adapter::Adapter() {
    phrases_player = {
            "hp",
            "armor",
            "basic_attack_damage",
            "attack_range",
            "using_item",
    };
    phrases_enemy = {
            "hp",
            "armor",
            "basic_attack_damage",
            "attack_range",
    };
    phrases_item = {
            "is damaging",
            "usages",
            "range",
    };
}

string Adapter::two_differs_to_player_info(size_t parameter_index, unsigned int old_value, unsigned int new_value) {
    string text = "";
    text += "Player's " + phrases_player[parameter_index] + " has changed from " + to_string(old_value)
            + " to " + to_string(new_value) + "\n";
    return text;
}

string Adapter::two_differs_to_item_info(size_t parameter_index, unsigned int old_value, unsigned int new_value) {
    string text = "";
    text += "Item's " + phrases_item[parameter_index] + " has changed from " + to_string(old_value)
            + " to " + to_string(new_value) + '\n';
    return text;
}

string Adapter::two_differs_to_enemy_info(size_t parameter_index, unsigned int old_value, unsigned int new_value) {
    string text = "";
    text += "Enemy's " + phrases_enemy[parameter_index] + " has changed from " + to_string(old_value)
            + " to " + to_string(new_value) + '\n';
    return text;
}



std::ostream& operator<<(std::ostream& out, const Player& player)
{
    std::string text =
            "\n[[Player info]]: "
            "\nHealth: " + to_string(player.get_curr_hp()) + "/" + to_string(player.get_max_hp()) +
            "\nArmor: " + to_string(player.get_armor()) +
            "\nAttackDamage: " + to_string(player.get_basic_attack_damage()) +
            "\nAttackRange: " + to_string(player.get_attack_range());
    bool has_item = player.get_using_item();
    text += "\nUsing item?: " + to_string(has_item);
    out << text;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Item& item)
{
    std::string text =
            "\n[[Item info]]: "
            "\nIs damaging: " + to_string(item.is_damaging()) +
            "\nUsages: " + to_string(item.get_usages()) +
            "\nRange: " + to_string(item.get_range());
    out << text;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Enemy& enemy)
{
    std::string text =
            "\n[[Enemy info]]: "
            "\nHealth: " + to_string(enemy.get_curr_hp()) + "/" + to_string(enemy.get_max_hp()) +
            "\nArmor: " + to_string(enemy.get_armor()) +
            "\nAttackDamage: " + to_string(enemy.get_basic_attack_damage()) +
            "\nAttackRange: " + to_string(enemy.get_attack_range());
    out << text;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Entity* entity)
{
    if (entity != nullptr) {
        auto player = dynamic_cast<const Player *>(entity);
        if (player) {
            out << *player << '\n';
            return out;
        }
        auto item = dynamic_cast <const Item *>(entity);
        if (item) {
            out << *item << '\n';
            return out;
        }
        auto enemy = dynamic_cast <const Enemy *>(entity);
        if (enemy) {
            out << *enemy << '\n';
            return out;
        }
    }
    return out;
}