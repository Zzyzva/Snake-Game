#include "Scene.h"


Scene::Scene(int id, int width, int height) {

	this->height = height;
	this->width = width;
	objects = new std::map<int, GameObject*>;
	xAdjust = 0;
	this->id = id;
	scripter = new ScriptManager();
	eventManager = new EventManager(id);
	
}

Scene::~Scene() {
	for (auto entry : *objects) {
		GameObject* o = entry.second;
		delete o;	
	}
	delete scripter;
	delete eventManager;
	delete objects;
}

std::map<int, GameObject*>* Scene::getObjects() {
	return objects;
}

void Scene::addObject(GameObject* o, int id) {
	getObjects()->insert(std::make_pair(id, o));
	totalID++;
}


void Scene::update(long currentTime, long deltaTime, EventManager* manager) {
	for (auto entry : *getObjects()) {
		GameObject* o = entry.second;
		o->update(currentTime, deltaTime, this, manager);
	}
}

void Scene::loadScene(Scene* newScene) {
	nextScene = newScene;
	endScene = true;
}

Scene* Scene::changeScene() {
	endScene = false;
	return nextScene;
}