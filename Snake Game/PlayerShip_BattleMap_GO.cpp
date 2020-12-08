#include "PlayerShip_BattleMap_GO.h"


PlayerShip_BattleMap_GO::PlayerShip_BattleMap_GO(Scene* scene, int id, int x, int y) {
    this->scene = scene;
    this->id = id;
    collider = new Collider(x, y, 48, 80, true);
    sf::RectangleShape* render = new sf::RectangleShape();
    if (!ship_texture.loadFromFile("Resources\\Pirates\\PlayerShip_BattleMap_Sprite.png")) {
        std::cout << "Failed to load ship texture";
    }
    render->setTexture(&ship_texture);
    render->setPosition(x, y);
    render->setSize(sf::Vector2f(48, 80));
    this->render = render;


    addComponent(new PlayerShip_BattleMap_COMP(scene, this));
    new PlayerShip_BattleMap_EH(scene, this);
}