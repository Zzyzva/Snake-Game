#include "LISTENERSnake.h"




LISTENERSnake::LISTENERSnake(Scene* scene, GOSnake* self) {
	this->scene = scene;
	this->self = self;
	scene->eventManager->registerHandler("SnakeMove", this);
	scene->eventManager->registerHandler("AppleHit", this);
	scene->eventManager->registerHandler("UpPressed", this);
	scene->eventManager->registerHandler("DownPressed", this);
	scene->eventManager->registerHandler("LeftPressed", this);
	scene->eventManager->registerHandler("RightPressed", this);



}

void LISTENERSnake::handleEvent(Event* e) {
	long time = e->getHandleTime();
	if (e->getName().compare("SnakeMove") == 0) {
		int x = 0;
		int y = 0;
		std::vector<Variant*>* list = e->getParams();
		for (Variant* v : *list) {
			if (v->name.compare("x") == 0) {
				x = v->i;
			}
			else if (v->name.compare("y") == 0) {
				y = v->i;
			}
		}
		self->slither(x, y, time);
	}



	if (e->getName().compare("UpPressed") == 0) {
		if (self->direction != 2) {
			self->direction = 0;
			self->render->setTexture(&self->tUp);
		}
		
	}
	if (e->getName().compare("RightPressed") == 0) {
		if (self->direction != 3) {
			self->direction = 1;
			self->render->setTexture(&self->tRight);

		}
	}
	if (e->getName().compare("DownPressed") == 0) {
		if (self->direction != 0) {
			self->direction = 2;
			self->render->setTexture(&self->tDown);
		}
	}
	if (e->getName().compare("LeftPressed") == 0) {
		if (self->direction != 1) {
			self->direction = 3;
			self->render->setTexture(&self->tLeft);
		}
	}
	
}