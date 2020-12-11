#pragma once

#include "Scene.h"

#include "PlayerShip_BattleMap_GO.h"
#include "EnemyShip_BattleMap_GO.h"
#include "Battle_GUI_GO.h"
#include "Rock_BattleMap_GO.h"

class PiratesClient

{
public:
    int static const battleMap_Top = 60;
    int static const battleMap_Bottom = 840;
    int static const battleMap_Right = 1540;
    int static const battleMap_Left = 760;

    void static piratesSetup(Scene* scene) {
        scene->addObject(new Battle_GUI_GO(scene, 0, 0, 0), 0);
        scene->addObject(new PlayerShip_BattleMap_GO(scene, 0, battleMap_Left + 100, battleMap_Top + 100), 1);
        scene->addObject(new EnemyShip_BattleMap_GO(scene, 0, 200, 200), 2);
        scene->addObject(new Rock_BattleMap_GO(scene, 0, battleMap_Left + 300, battleMap_Top + 300), 3);
    }

};

