//
// Created by Deimos on 07.11.2021.
//

#include "Observer.h"

void Observer::add_object(const Entity *entity) {
    if (entity != nullptr) {
        const Player *player = dynamic_cast<const Player *>(entity);
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

    if (player->get_and_restore_has_changed()) {
        const size_t vect_size = 5;
        auto old_stats = objects_cache[player];
        std::vector <unsigned int> new_player_stats = {
                player->get_curr_hp(),
                player->get_armor(),
                player->get_basic_attack_damage(),
                player->get_attack_range(),
                player->get_using_item(),
        };

        bool differs = false;
        for (size_t i = 0; i < vect_size; ++i) {
            if (new_player_stats[i] != old_stats[i]) {
                differs = true;
                text += adapter.two_differs_to_player_info(i, old_stats[i], new_player_stats[i]);
            }
        }
        if (differs) {
            objects_cache[player] = new_player_stats;
        }
    }
    return text;
}

std::string Observer::check_item(const Item *item) {
    std::string text = "";

    if (item->get_and_restore_has_changed()) {

        const size_t vect_size = 3;
        auto old_stats = objects_cache[item];
        std::vector<unsigned int> new_item_stats = {
                item->is_damaging(),
                item->get_usages(),
                item->get_range(),
        };

        bool differs = false;
        for (size_t i = 0; i < vect_size; ++i) {
            if (new_item_stats[i] != old_stats[i]) {
                differs = true;
                text += adapter.two_differs_to_item_info(i, old_stats[i], new_item_stats[i]);
            }
        }

        if (differs) {
            objects_cache[item] = new_item_stats;
        }

    }
    return text;
}

std::string Observer::check_enemy(const Enemy *enemy) {
    std::string text = "";

    if (enemy->get_and_restore_has_changed()) {
        const size_t vect_size = 4;
        auto old_stats = objects_cache[enemy];
        std::vector<unsigned int> new_enemy_stats = {
                enemy->get_curr_hp(),
                enemy->get_armor(),
                enemy->get_basic_attack_damage(),
                enemy->get_attack_range(),
        };

        bool differs = false;
        for (size_t i = 0; i < vect_size; ++i) {
            if (new_enemy_stats[i] != old_stats[i]) {
                differs = true;
                text += adapter.two_differs_to_enemy_info(i, old_stats[i], new_enemy_stats[i]);
            }
        }

        if (differs) {
            objects_cache[enemy] = new_enemy_stats;
        }
    }
    return text;
}

Observer::Observer() {

}

void Observer::remove_object(const Entity *entity) {
    if (objects_cache.find(entity) != objects_cache.end())
    {
        objects_cache.erase(entity);
    }
}

std::string Observer::check_objects() {
    string text = "";
    for (const auto& subsriber: objects_cache)
    {
        text += this->check_object(subsriber.first);
    }
    return text;
}

void Observer::remove_all() {
    objects_cache.clear();
}
