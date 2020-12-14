#pragma once

#include <algorithm> 
#include <queue>

#include "Component.h"

#include "PlayerShip_BattleMap_GO.h"


class PlayerShip_BattleMap_GO;

class ShipMovement_BattleMap_COMP : public Component
{

    Scene* scene;
    GameObject* self;
    


public:
    float speed = 0;
    Point velocity;
    Point target;
    std::queue<Point> targetQueue;
    bool targeting = false;
    bool pathing = false;


    ShipMovement_BattleMap_COMP(Scene* scene, GameObject* self);

    void update(long currentTime, long deltaTime);
};

