#pragma once

#include "GameObject.h"

#include "EnemyShip_BattleMap_COMP.h"
#include "EnemyShip_BattleMap_EH.h"

class EnemyShip_BattleMap_COMP;
class EnemyShip_BattleMap_EH;

class EnemyShip_BattleMap_GO : public GameObject
{   
    sf::Texture ship_texture;
    
    public:
    int angle = 160;
    float speed = 5;
    Point velocity;
    
    EnemyShip_BattleMap_GO( Scene* scene, int id, int x, int y );
};