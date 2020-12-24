#pragma once

#include "GameObject.h"

#include "ShipMovement_BattleMap_COMP.h"
#include "PlayerShip_BattleMap_EH.h"

#include "ShipHealth_COMP.h"
#include "ShipHealth_EH.h"


class ShipMovement_BattleMap_COMP;
class PlayerShip_BattleMap_EH;

class PlayerShip_BattleMap_GO : public GameObject
{
    sf::Texture ship_texture;
    
public:
    int angle = 180;
    ShipMovement_BattleMap_COMP* movement;

    PlayerShip_BattleMap_GO(Scene* scene, int id, int x, int y);
};

