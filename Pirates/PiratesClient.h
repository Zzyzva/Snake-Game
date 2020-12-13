#pragma once

#include "Scene.h"

#include "PlayerShip_BattleMap_GO.h"
#include "EnemyShip_BattleMap_GO.h"
#include "Battle_GUI_GO.h"
#include "Rock_BattleMap_GO.h"

#include "Ship_GUI_GO.h"
#include "Crewmate_GO.h"

class PiratesClient

{
public:
    int static const battleMap_Top = 60;
    int static const battleMap_Bottom = 840;
    int static const battleMap_Right = 1540;
    int static const battleMap_Left = 760;

    // Overview coordinates
    static const int OVERVIEW_LEFT = 60;
    static const int OVERVIEW_TOP = 360;
    static const int OVERVIEW_RIGHT = 690;
    static const int OVERVIEW_BOTTOM = 840;

    void static piratesSetup(Scene* scene) {
        scene->addObject(new Battle_GUI_GO(scene, 0, 0, 0), 0);
        scene->addObject(new PlayerShip_BattleMap_GO(scene, 0, battleMap_Left + 100, battleMap_Top + 100), 1);
        scene->addObject(new EnemyShip_BattleMap_GO(scene, 0, 200, 200), 2);
        scene->addObject(new Rock_BattleMap_GO(scene, 0, battleMap_Left + 300, battleMap_Top + 300), 3);

        // TODO fix the numbers

        // Overview (reserve ids 50-99)
        scene->addObject(new Ship_GUI_GO(scene, 0, ( OVERVIEW_LEFT + OVERVIEW_RIGHT ) / 2 + 250, ( OVERVIEW_TOP + OVERVIEW_BOTTOM ) / 2 - 125 ), 50);
        scene->addObject(new Crewmate_GO(scene, 0, ( OVERVIEW_LEFT + OVERVIEW_RIGHT ) / 2, ( OVERVIEW_TOP + OVERVIEW_BOTTOM ) / 2 - 125), 51);
    }

};

