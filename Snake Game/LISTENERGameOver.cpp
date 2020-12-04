#include "LISTENERGameOver.h"


LISTENERGameOver::LISTENERGameOver(Scene* scene) {
	this->scene = scene;
	scene->eventManager->registerHandler("GameOver", this);
	scene->eventManager->registerHandler("SpacePressed", this);
}

void LISTENERGameOver::handleEvent(Event* e) {
	if (e->getName().compare("GameOver") == 0) {
		Scene* newScene = new Scene(scene->id, scene->width, scene->height);
		int id = scene->totalID;
		newScene->addObject(new GOGameOver(id), id);
		new LISTENERGameOver(newScene);
		scene->loadScene(newScene);

	}
	if (e->getName().compare("SpacePressed") == 0) {
		
		Scene* newScene = new Scene(scene->id, scene->width, scene->height);
		newScene->addObject(new GOSnake(newScene, 0, 3, 200, 200), 0);
		newScene->addObject(new GOApple(newScene, 4, 300, 300), 4);
		new LISTENERGameOver(newScene);
		scene->loadScene(newScene);
	}
}