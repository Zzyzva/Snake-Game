#include "Rock_BattleMap_GO.h"


Rock_BattleMap_GO::Rock_BattleMap_GO(Scene* scene, int id, int x, int y) {
    this->scene = scene;
    this->id = id;
    collider = new Collider(x, y, 64, 64, true);

    sf::RectangleShape* render = new sf::RectangleShape();
    render->setPosition(x, y);
    render->setSize(sf::Vector2f(64, 64));
    render->setFillColor(sf::Color(sf::Color::White));
    this->render = render;
}