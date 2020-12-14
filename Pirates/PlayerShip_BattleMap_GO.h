#pragma once

#include "GameObject.h"

#include "PlayerShip_BattleMap_COMP.h"
#include "PlayerShip_BattleMap_EH.h"

#include "ShipHealth_COMP.h"
#include "ShipHealth_EH.h"


class PlayerShip_BattleMap_COMP;
class PlayerShip_BattleMap_EH;

class PlayerShip_BattleMap_GO : public GameObject
{
    sf::Texture ship_texture;
    
public:
    int angle = 180;
    float speed = 0;
    Point velocity;
    Point target;
    bool targeting = false;

    PlayerShip_BattleMap_GO(Scene* scene, int id, int x, int y);
};

