#pragma once
#include "Event.h"
#include "Scene.h"

class Scene;

class EventHandler
{
public:
	int id;
	Scene* scene;
	virtual void handleEvent(Event* e) = 0;
};

