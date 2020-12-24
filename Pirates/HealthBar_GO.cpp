#include "HealthBar_GO.h"

/** Width of the ship sprite */
static constexpr int const& SPRITE_WIDTH = 665;

/** Height of the ship sprite */
static constexpr int const& SPRITE_HEIGHT = 150;

/** Direction ship is facing */
static constexpr int const& SPRITE_ANGLE = 0;


HealthBar_GO::HealthBar_GO(Scene* scene, int id, int x, int y)
{
    this->scene = scene;
    this->id = id;
    collider = new Collider(x, y, SPRITE_WIDTH, SPRITE_HEIGHT, false);

    // Set Sprite
    sf::RectangleShape* render = new sf::RectangleShape();

    // Ensure sprite is loaded
    if (!texture.loadFromFile("Resources\\Pirates\\Overview\\water_level_bar.png")) {
        std::cout << "Failed to load overview health bar texture";
    }

    // Set sprite details
    render->setTexture(&texture);
    render->setPosition(x, y);
    render->setRotation(SPRITE_ANGLE);
    render->setSize(sf::Vector2f(SPRITE_WIDTH, SPRITE_HEIGHT));

    this->render = render;
}