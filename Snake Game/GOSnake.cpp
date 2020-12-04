#include "GOSnake.h"

//0 North, 1 East, 2 South, 3 West
constexpr int interval = 20;


GOSnake::GOSnake(Scene* scene, int id, int count, int x, int y) {
	this->scene = scene;
	this->id = id;

	sf::RectangleShape* render = new sf::RectangleShape();
	if (!tUp.loadFromFile("Resources\\AntUp.png")) {
		std::cout << "Failed to load player texture";
	}
	if (!tRight.loadFromFile("Resources\\AntRight.png")) {
		std::cout << "Failed to load player texture";
	}
	if (!tDown.loadFromFile("Resources\\AntDown.png")) {
		std::cout << "Failed to load player texture";
	}
	if (!tLeft.loadFromFile("Resources\\AntLeft.png")) {
		std::cout << "Failed to load player texture";
	}
	render->setTexture(&tRight);
	render->setPosition(x, y);
	render->setSize(sf::Vector2f(20, 20));

	collider = new Collider(x, y, 20, 20, true);
	//sf::RectangleShape* render = new sf::RectangleShape();
	//render->setPosition(x, y);
	//render->setSize(sf::Vector2f(20, 20));
	//render->setFillColor(sf::Color::White);
	this->render = render;


	if (count == 3) {
		addComponent(new COMPSnake(scene, this));
		new LISTENERSnake(scene, this);
		head = true;
	}
	
	if (count > 1) {
		follower = new GOSnake(scene, ++id, --count, x - 20, y);
		scene->addObject(follower, ++id);
	}
}

void GOSnake::slither(int x, int y, long time) {
	if (willGrow > 0) {
		follower = new GOSnake(scene, ++scene->totalID, 1, collider->getX(), collider->getY());
		follower->willGrow = --willGrow;
		scene->addObject(follower, ++scene->totalID);
		willGrow = 0;
		follower->direction = direction;
	}
	if (direction == 0) {
		render->setTexture(&tUp);
	}
	if (direction == 1) {
		render->setTexture(&tRight);
	}
	if (direction == 2) {
		render->setTexture(&tDown);
	}
	if (direction == 3) {
		render->setTexture(&tLeft);
	}

	if (follower) {
		
		follower->slither(collider->getX(), collider->getY(), time);
		follower->direction = direction;
		
	}
	if (head) {
		if (x < 0 || y < 0 || x >= 400 || y >= 400 || follower->checkCollision(x, y)) {
			Event* e = new Event("GameOver", time, scene->id);
			scene->eventManager->raise(e);
		}
	}
	
	collider->setPosition(x, y);
	
}

bool GOSnake::checkCollision(int x, int y) {
	if (follower) {
		if ((x == collider->getX() && y == collider->getY()) || follower->checkCollision(x, y)) {
			return true;
		}
	}
	else {
		if (x == collider->getX() && y == collider->getY()) {
			return true;
		}
	}
	
	return false;
}

void GOSnake::moveSnake(long time) {
	int x;
	int y;
	if (direction == 0) {
		x = collider->getX();
		y = collider->getY() - interval;
	}
	if (direction == 1) {
		x = collider->getX() + interval;
		y = collider->getY();
	}
	if (direction == 2) {
		x = collider->getX();
		y = collider->getY() + interval;
	}
	if (direction == 3) {
		x = collider->getX() - interval;
		y = collider->getY();
	}
	Event* e = new Event("SnakeMove", time, scene->id);
	Variant* v1 = new Variant("x", VINT);
	v1->i = x;
	e->addParam(v1);
	Variant* v2 = new Variant("y", VINT);
	v2->i = y;
	e->addParam(v2);
	scene->eventManager->raise(e);
}

void GOSnake::grow() {
	if (follower) {
		follower->grow();
	}
	else {
		willGrow = 2;
	}
}