#pragma once

#include "Scene.h"

#include "BattleMap_Setup.h"
#include "ShipOverview_Setup.h"

class PiratesClient

{
public:
    void static piratesSetup(Scene* scene) { 
        BattleMap_Setup::battleMapSetup(scene);
        ShipOverview_Setup::shipOverviewSetup(scene);
    }
};

