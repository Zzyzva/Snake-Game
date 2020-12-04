#pragma once
#include "EventHandler.h"
#include "Scene.h"
#include "GOSnake.h"
#include "dukglue/dukglue.h"

class GOSnake;

class LISTENERSnake : public EventHandler
{
public:
	Scene* scene;
	GOSnake* self;

	LISTENERSnake(Scene* scene, GOSnake* self);

	void handleEvent(Event* e);
};

