#pragma once
#include "EventHandler.h"
#include "Scene.h"
#include "GOGameOver.h"
#include "GOSnake.h"
#include "GOApple.h"

class LISTENERGameOver : public EventHandler
{
public:
	Scene* scene;

	LISTENERGameOver(Scene* scene);

	void handleEvent(Event* e);
};

