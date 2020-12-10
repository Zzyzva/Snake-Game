#pragma once
#include "EventHandler.h"
#include "GOApple.h"

class GOApple;

class LISTENERApple : public EventHandler
{
public:
	GOApple* self;

	LISTENERApple(Scene* scene, GOApple* self);

	void handleEvent(Event* e);
};

