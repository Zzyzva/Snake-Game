#pragma once

#include "Scene.h"
#include "PlayerShip_BattleMap_GO.h"
#include "EnemyShip_BattleMap_GO.h"

class PiratesClient

{
public:
    void static piratesSetup(Scene* scene) {
        scene->addObject(new PlayerShip_BattleMap_GO(scene, 0, 500, 400), 0);
        scene->addObject(new EnemyShip_BattleMap_GO(scene, 0, 200, 200), 1);
    }

};

