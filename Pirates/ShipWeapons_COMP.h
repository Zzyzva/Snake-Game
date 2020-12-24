#pragma once

#include "Component.h"

class ShipWeapons_COMP : public Component
{

    Scene* scene;
    GameObject* self;
public:
    ShipWeapons_COMP(Scene* scene, GameObject* self);

    void update(long currentTime, long deltaTime);

    bool inRange(float x, float y, int faceAngle, int angleRange, float range);
};


