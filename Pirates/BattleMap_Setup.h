#pragma once

#include "Scene.h"

#include "PlayerShip_BattleMap_GO.h"
#include "EnemyShip_BattleMap_GO.h"
#include "Battle_GUI_GO.h"
#include "Rock_BattleMap_GO.h"

class BattleMap_Setup
{
public:
    int static const battleMap_Top = 60;
    int static const battleMap_Bottom = 840;
    int static const battleMap_Right = 1540;
    int static const battleMap_Left = 760;

    static void battleMapSetup(Scene* scene) {
        scene->addObject(new Battle_GUI_GO(scene, scene->getNextID(), 0, 0));
        scene->addObject(new PlayerShip_BattleMap_GO(scene, scene->getNextID(), battleMap_Left + 100, battleMap_Top + 100));
        scene->addObject(new EnemyShip_BattleMap_GO(scene, scene->getNextID(), 200, 200));
        scene->addObject(new Rock_BattleMap_GO(scene, scene->getNextID(), battleMap_Left + 300, battleMap_Top + 300));
    }
};

