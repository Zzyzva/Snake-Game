#pragma once
#include "GameObject.h"
#include "LISTENERApple.h"

class LISTENERApple;


class GOApple : public GameObject
{
public:
	Scene* scene;

	GOApple(Scene* scene, int id, int x, int y);
};

