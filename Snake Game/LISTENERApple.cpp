#include "LISTENERApple.h"

LISTENERApple::LISTENERApple(Scene* scene, GOApple* self) {
	this->scene = scene;
	this->self = self;
	scene->eventManager->registerHandler("SnakeMove", this);
	scene->eventManager->registerHandler("AppleHit", this);
}

void LISTENERApple::handleEvent(Event* e) {
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
		if (x == self->collider->getX() && y == self->collider->getY()){
			Event* e2 = new Event("AppleHit", scene->id, e->getHandleTime());
			scene->eventManager->raise(e2);
		}
	}

	if (e->getName().compare("AppleHit") == 0) {
		int x;
		int y;
		bool valid = false;
		while (!valid) {
			x = rand() % 20;
			y = rand() % 20;
			x *= 20;
			y *= 20;
			valid = true;
			for (auto entry : *scene->getObjects()) {
				GameObject* o = entry.second;
				if (o->collider->getX() == x && o->collider->getY() == y) {
					valid = false;
					break;
				}
			}
		}
		self->collider->setPosition(x, y);
		
	}
}