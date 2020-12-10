#pragma once

#include "Scene.h"
#include "PlayerShip_BattleMap_GO.h"
#include "EnemyShip_BattleMap_GO.h"
#include "Battle_GUI_GO.h"

class PiratesClient

{
public:
    void static piratesSetup(Scene* scene) {
        scene->addObject(new Battle_GUI_GO(scene, 0, 0, 0), 0);
        scene->addObject(new PlayerShip_BattleMap_GO(scene, 0, 500, 400), 1);
        scene->addObject(new EnemyShip_BattleMap_GO(scene, 0, 200, 200), 2);
    }

};

