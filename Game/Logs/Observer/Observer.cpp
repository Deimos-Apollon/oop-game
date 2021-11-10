//
// Created by Deimos on 07.11.2021.
//

#include "Observer.h"

void Observer::add_object(const Entity *entity) {
    if (entity != nullptr) {
        auto player = dynamic_cast<const Player *>(entity);
        if (player) {
            add_player(player);
        }
        auto item = dynamic_cast <const Item *>(entity);
        if (item) {
            add_item(item);
        }
        auto enemy = dynamic_cast <const Enemy *>(entity);
        if (enemy) {
            add_enemy(enemy);
        }
    }
}

void Observer::add_player(const Player *player) {
    std::vector <unsigned int> player_stats = {
                            player->get_curr_hp(),
                            player->get_armor(),
                            player->get_basic_attack_damage(),
                            player->get_attack_range(),
                            player->get_using_item(),
                            };

    objects_cache[player] = player_stats;
}

void Observer::add_item(const Item *item) {
    std::vector <unsigned int> item_stats = {
            item->is_damaging(),
            item->get_usages(),
            item->get_range()
    };
    objects_cache[item] = item_stats;
}

void Observer::add_enemy(const Enemy *enemy) {
    std::vector <unsigned int> enemy_stats =
            {
                enemy->get_curr_hp(),
                enemy->get_armor(),
                enemy->get_basic_attack_damage(),
                enemy->get_attack_range(),
            };
    objects_cache[enemy] = enemy_stats;
}


std::string Observer::check_object(const Entity *entity) {
    if (entity != nullptr) {
        auto player = dynamic_cast<const Player *>(entity);
        if (player) {
            return check_player(player);
        }
        auto item = dynamic_cast <const Item *>(entity);
        if (item) {
            return check_item(item);
        }
        auto enemy = dynamic_cast <const Enemy *>(entity);
        if (enemy) {
            return check_enemy(enemy);
        }
    }
    return "";
}

std::string Observer::check_player(const Player *player) {
    std::string text = "";
    const size_t vect_size = 5;
    auto old_stats = objects_cache[player];
    std::vector <unsigned int> new_player_stats = {
            player->get_curr_hp(),
            player->get_armor(),
            player->get_basic_attack_damage(),
            player->get_attack_range(),
            player->get_using_item(),
    };
    std::vector <size_t> mismatched_indexes;
    for (size_t i = 0; i < vect_size; ++i)
    {
        if (new_player_stats[i] != old_stats[i])
        {
            mismatched_indexes.push_back(i);
        }
    }
    for (auto index: mismatched_indexes)
    {
        text += "Player's " + phrases_player[index] + " has changed from " + to_string(old_stats[index])
                + " to " + to_string(new_player_stats[index]);
    }
    if (!mismatched_indexes.empty()) {
        text += '\n';
        objects_cache[player] = new_player_stats;
    }
    return text;
}

std::string Observer::check_item(const Item *item) {
    std::string text = "";
    const size_t vect_size = 3;
    auto old_stats = objects_cache[item];
    std::vector <unsigned int> new_item_stats = {
            item->is_damaging(),
            item->get_usages(),
            item->get_range(),
    };
    std::vector <size_t> mismatched_indexes;
    for (size_t i = 0; i < vect_size; ++i)
    {
        if (new_item_stats[i] != old_stats[i])
        {
            mismatched_indexes.push_back(i);
        }
    }
    for (auto index: mismatched_indexes)
    {
        text += "Item's " + phrases_item[index] + " has changed from " + to_string(old_stats[index])
                + " to " + to_string(new_item_stats[index]);
    }
    if (!mismatched_indexes.empty()) {
        text += '\n';
        objects_cache[item] = new_item_stats;
    }
    return text;
}

std::string Observer::check_enemy(const Enemy *enemy) {
    std::string text = "";
    const size_t vect_size = 4;
    auto old_stats = objects_cache[enemy];
    std::vector <unsigned int> new_enemy_stats = {
            enemy->get_curr_hp(),
            enemy->get_armor(),
            enemy->get_basic_attack_damage(),
            enemy->get_attack_range(),
    };
    std::vector <size_t> mismatched_indexes;
    for (size_t i = 0; i < vect_size; ++i)
    {
        if (new_enemy_stats[i] != old_stats[i])
        {
            mismatched_indexes.push_back(i);
        }
    }
    for (auto index: mismatched_indexes)
    {
        text += "Enemy's " + phrases_enemy[index] + " has changed from " + to_string(old_stats[index])
                + " to " + to_string(new_enemy_stats[index]);
    }
    if (!mismatched_indexes.empty()) {
        text += '\n';
        objects_cache[enemy] = new_enemy_stats;
    }
    return text;
}

Observer::Observer() {
    phrases_player = {
            {0, "hp"},
            {1, "armor"},
            {2, "basic_attack_damage"},
            {3, "attack_range"},
            {4, "using_item"},
    };
    phrases_enemy = {
            {0, "hp"},
            {1, "armor"},
            {2, "basic_attack_damage"},
            {3, "attack_range"},
    };
    phrases_item = {
            {0, "is damaging"},
            {1, "usages"},
            {2, "range"},
    };
}
