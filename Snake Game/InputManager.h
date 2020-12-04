#pragma once
#include "EventManager.h"
#include <SFML/Graphics.hpp>
#include "Scene.h"

/**
*Checks for all inputs and raises events for them
*/
class InputManager
{
	Scene* scene;
	bool* focus;
	bool enterPressed = false;
	bool downPressed = false;
	bool rightPressed = false;
	bool leftPressed = false;
	bool spacePressed = false;
	bool PPressed = false;
	bool upPressed = false;
public:

	//Creates the manager
	InputManager(Scene* scene, bool* focus);

	//Checks for input, called every loop
	void checkInput(long time);

	void updateScene(Scene* scene);
};

