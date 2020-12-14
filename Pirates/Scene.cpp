#include "Scene.h"


Scene::Scene(int id, int width, int height) {

	this->height = height;
	this->width = width;
	objects = new std::map<int, GameObject*>;
	xAdjust = 0;
	this->id = id;
	eventManager = new EventManager(id);
	
}

Scene::~Scene() {
	for (auto entry : *objects) {
		GameObject* o = entry.second;
		delete o;	
	}
	delete eventManager;
	delete objects;
}

std::map<int, GameObject*>* Scene::getObjects() {
	return objects;
}

void Scene::addObjectByID(GameObject* o, int id) {
	getObjects()->insert(std::make_pair(id, o));
	totalID++;
}
void Scene::addObject(GameObject* o) {
	getObjects()->insert(std::make_pair(totalID, o));
	totalID++;
}

int Scene::getNextID() {
	return totalID;
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