#pragma once

#include "Component.h"

#include "PlayerShip_BattleMap_GO.h"


class PlayerShip_BattleMap_GO;

class PlayerShip_BattleMap_COMP : public Component
{

    Scene* scene;
    PlayerShip_BattleMap_GO* self;



public:

    PlayerShip_BattleMap_COMP(Scene* scene, PlayerShip_BattleMap_GO* self);

    void update(long currentTime, long deltaTime);
};

