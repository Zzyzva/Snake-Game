#pragma once

#include "Component.h"

#include "EnemyShip_BattleMap_GO.h"

class EnemyShip_BattleMap_GO;

class EnemyShip_BattleMap_COMP : public Component
{
    Scene* scene;
    EnemyShip_BattleMap_GO* self;
    
    public:
    
    EnemyShip_BattleMap_COMP( Scene* scene, EnemyShip_BattleMap_GO* self );
    void update( long currentTime, long deltaTime );
};