#pragma once

#include "EventHandler.h"

#include "EnemyShip_BattleMap_GO.h"

class EnemyShip_BattleMap_GO;

class EnemyShip_BattleMap_EH : public EventHandler
{
    public:
    
    EnemyShip_BattleMap_GO* self;
    
    EnemyShip_BattleMap_EH( Scene* scene, EnemyShip_BattleMap_GO* self );
    
    void handleEvent( Event* e );
};