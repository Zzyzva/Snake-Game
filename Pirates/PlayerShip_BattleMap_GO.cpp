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


    addComponent(new ShipHealth_COMP(scene, this, 100));
    new ShipHealth_EH(scene, this);

    collider->setAngle(180);

    movement = new ShipMovement_BattleMap_COMP(scene, this);
    addComponent(movement);
    new PlayerShip_BattleMap_EH(scene, this);
}