#pragma once

#include "Scene.h"

#include "Ship_GUI_GO.h"
#include "Crewmate_GO.h"

class ShipOverview_Setup
{
    // Overview coordinates
    static const int OVERVIEW_LEFT = 60;
    static const int OVERVIEW_TOP = 360;
    static const int OVERVIEW_RIGHT = 690;
    static const int OVERVIEW_BOTTOM = 840;
public:
    static void shipOverviewSetup(Scene* scene) {
        scene->addObject(new Ship_GUI_GO(scene, scene->getNextID(), (OVERVIEW_LEFT + OVERVIEW_RIGHT) / 2 + 250, (OVERVIEW_TOP + OVERVIEW_BOTTOM) / 2 - 125));
        scene->addObject(new Crewmate_GO(scene, scene->getNextID(), (OVERVIEW_LEFT + OVERVIEW_RIGHT) / 2, (OVERVIEW_TOP + OVERVIEW_BOTTOM) / 2 - 125));
    }
};

