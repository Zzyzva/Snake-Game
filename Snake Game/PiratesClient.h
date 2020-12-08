#pragma once

#include "Scene.h"
#include "PlayerShip_BattleMap_GO.h"

class PiratesClient

{
public:
    void static piratesSetup(Scene* scene) {
        scene->addObject(new PlayerShip_BattleMap_GO(scene, 0, 40, 40), 0);
    }

};

