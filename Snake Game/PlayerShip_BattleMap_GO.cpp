#include "PlayerShip_BattleMap_GO.h"

static constexpr int const& SPRITE_SIZE = 128;

PlayerShip_BattleMap_GO::PlayerShip_BattleMap_GO(Scene* scene, int id, int x, int y) {
    this->scene = scene;
    this->id = id;
    collider = new Collider(x, y, SPRITE_SIZE, SPRITE_SIZE, true);

    //Set Sprite
    sf::RectangleShape* render = new sf::RectangleShape();
    if (!ship_texture.loadFromFile("Resources\\Pirates\\PlayerShip_BattleMap_Sprite.png")) {
        std::cout << "Failed to load ship texture";
    }

    
    render->setTexture(&ship_texture);
    render->setPosition(x, y);
    render->setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    render->setOrigin(SPRITE_SIZE / 2, SPRITE_SIZE / 2);
    render->setRotation(angle);
    this->render = render;


    addComponent(new PlayerShip_BattleMap_COMP(scene, this));
    new PlayerShip_BattleMap_EH(scene, this);

    velocity.x = 0;
    velocity.y = 0;
}