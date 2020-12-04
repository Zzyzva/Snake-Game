#pragma once

#include "Scene.h"
#include "EventManager.h"

class GameObject;
class Scene;

/**
* Virtual class for any script that a game object could run
*/
class Component
{
public:
	virtual void update(long currentTime, long deltaTime) = 0;

};

