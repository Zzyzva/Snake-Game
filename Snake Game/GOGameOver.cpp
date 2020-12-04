#include "GOGameOver.h"


GOGameOver::GOGameOver(int id) {
	sf::RectangleShape* render = new sf::RectangleShape();
	if (!t.loadFromFile("Resources\\GameOver.png")) {
		std::cout << "Failed to load player texture";
	}
	render->setTexture(&t);
	render->setPosition(0, 0);
	render->setSize(sf::Vector2f(400, 400));
	this->render = render;


	collider = new Collider(0, 0, 400, 400, false);

}

