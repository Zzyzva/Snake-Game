#pragma once
#include <vector>
#include "GameObject.h"
#include "EventManager.h"
#include "Point.h"
#include "ScriptManager.h"
#include "dukglue/dukglue.h"

class GameObject;
class Component;
class ScriptManager;

/**
* Represenetaion of all objects currently being used
*/
class Scene
{
public:
	int height; //Height of scene
	int width; //Width of scene
	float xAdjust; //Relative adjustment of scene
	std::map<int, GameObject*>* objects; //All objects in the scene, sorted by their Unique id
	int id;
	int playbackXAdjust = 0;
	int totalID = 0;

	ScriptManager* scripter;
	EventManager* eventManager;

	Scene* nextScene;
	bool endScene = false;

	Scene(int id, int width, int height); //Creates a new scene with an empty object map 

	~Scene();

	std::map<int, GameObject*>* getObjects(); //Returns the map of objects

	void update(long currentTime, long deltaTime, EventManager* manager); //Updates all the objects in the scene;

	void addObject(GameObject* o, int id);

	void loadScene(Scene* newScene);

	Scene* changeScene();
};

