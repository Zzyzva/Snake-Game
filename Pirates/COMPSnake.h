#pragma once

#include "Component.h"
#include "GOSnake.h"

class GOSnake;

class COMPSnake : public Component
{
public:
	GOSnake* self;
	Scene* scene;


	int moveTic = 10;
	int lastMove = 0;

	COMPSnake(Scene* scene, GOSnake* self);

	void update(long currentTime, long deltaTime);
};

