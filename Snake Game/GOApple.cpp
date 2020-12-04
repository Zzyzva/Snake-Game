#include "GOApple.h"

GOApple::GOApple(Scene* scene, int id, int x, int y) {
	this->scene = scene;
	this->id = id;
	collider = new Collider(x, y, 20, 20, true);
	sf::RectangleShape* render = new sf::RectangleShape();
	render->setPosition(x, y);
	render->setSize(sf::Vector2f(20, 20));
	render->setFillColor(sf::Color::Red);
	this->render = render;

	new LISTENERApple(scene, this);
}