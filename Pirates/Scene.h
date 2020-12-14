#pragma once
#include <vector>
#include "GameObject.h"
#include "EventManager.h"
#include "Point.h"


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
	int id; //ID of the scene
	int totalID = 0; //Next available ID

	EventManager* eventManager; //Event Manger for the scene

	Scene* nextScene; //Next scene, used for changing scenes
	bool endScene = false;// True if the scene is about to change

	Scene(int id, int width, int height); //Creates a new scene with an empty object map 

	~Scene(); //Delets the scene

	std::map<int, GameObject*>* getObjects(); //Returns the map of objects

	void update(long currentTime, long deltaTime, EventManager* manager); //Updates all the objects in the scene;

	void addObjectByID(GameObject* o, int id); //Adds an object to the given ID

	void addObject(GameObject* o); //Adds an object to the next available ID

	int getNextID(); //returns the next available ID

	void loadScene(Scene* newScene);

	Scene* changeScene();
};

