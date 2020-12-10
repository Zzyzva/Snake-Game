#include "COMPSnake.h"


COMPSnake::COMPSnake(Scene* scene, GOSnake* self) {
	this->scene = scene;
	this->self = self;
}

void COMPSnake::update(long currentTime, long deltaTime) {
	if (currentTime - lastMove > moveTic) {
		self->moveSnake(currentTime);
		lastMove = currentTime;
	}
}