//
// Created by Deimos on 12.10.2021.
//

#ifndef OOP_GAME_LEVEL_H
#include "../entities/Creatures/Player/Player.h"
#include "../field/Field.h"
#include "../entities/Creatures/Enemies/Enemy/Enemy.h"
#include "LevelInterface/LevelInterface.h"
#include "../CLI_Interface/level_interface/LevelView.h"
#include "../classes-interfacesd/AIStrategy/ApproachStrategy/ApproachStrategy.h"
#include "../entities/Items/MeleeDamageItems/Axe/Axe.h"
#include <conio.h>
#define OOP_GAME_LEVEL_H

using namespace std;

class Level : public LevelInterface{
    Player* player = nullptr;
    Field* field = nullptr;
    vector <Enemy*> enemies = {};
    vector <Item*> items = {};
    unsigned int enemies_num = 0;
    FieldIterator* fi = new FieldIterator(*field); // TODO delete
    LevelView* lw = new LevelView(*fi); // TODO delete
private:
    void proceed() override;
    void finish() override;
public:
    explicit Level(Player* player = nullptr, Field* field= nullptr, vector <Enemy*> enemies = {}, unsigned int enemies_num = 0
            , vector <Item*> items = {});
    void start() override;
};


#endif //OOP_GAME_LEVEL_H
