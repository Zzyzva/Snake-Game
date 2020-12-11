#include "PlayerShip_BattleMap_GO.h"

static constexpr int const& SPRITE_WIDTH = 24;
static constexpr int const& SPRITE_HEIGHT = 48;

PlayerShip_BattleMap_GO::PlayerShip_BattleMap_GO(Scene* scene, int id, int x, int y) {
    this->scene = scene;
    this->id = id;
    collider = new Collider(x, y, SPRITE_WIDTH, SPRITE_HEIGHT, true);

    //Set Sprite
    sf::RectangleShape* render = new sf::RectangleShape();
    if (!ship_texture.loadFromFile("Resources\\Pirates\\PlayerShip_BattleMap_Sprite.png")) {
        std::cout << "Failed to load ship texture";
    }

    
    render->setTexture(&ship_texture);
    render->setPosition(x, y);
    render->setSize(sf::Vector2f(SPRITE_WIDTH, SPRITE_HEIGHT));
    render->setOrigin(SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2);
    render->setRotation(angle);
    collider->setCenterOrigin(true);
    this->render = render;


    addComponent(new PlayerShip_BattleMap_COMP(scene, this));
    new PlayerShip_BattleMap_EH(scene, this);

    velocity.x = 0;
    velocity.y = 0;

    target.x = 0;
    target.y = 0;
}