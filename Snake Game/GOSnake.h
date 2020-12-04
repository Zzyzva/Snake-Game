#pragma once

#include "GameObject.h"
#include "COMPSnake.h"
#include "LISTENERSnake.h"

#include <vector>

class COMPSnake;
class LISTENERSnake;

class GOSnake : public GameObject
{
public:
	Scene* scene;
	int id;
	GOSnake* follower;
	bool head = false;
	int willGrow = 0;
	int direction = 1;
	int tempDirection = 1;
	sf::Texture tUp;
	sf::Texture tDown;
	sf::Texture tLeft;
	sf::Texture tRight;

	GOSnake(Scene* scene, int id, int count, int x, int y);

	void slither(int x, int y, long time);

	bool checkCollision(int x, int y);

	void moveSnake(long time);

	void grow();
};

