#include "Crewmate_GO.h"

/** Width of the ship sprite */
static constexpr int const& SPRITE_WIDTH = 200;

/** Height of the ship sprite */
static constexpr int const& SPRITE_HEIGHT = 200;

/** Direction ship is facing */
static constexpr int const& SPRITE_ANGLE = 0;

/** Crewmate starting health */
static constexpr int const& MAX_HEALTH = 100;

Crewmate_GO::Crewmate_GO(Scene* scene, int id, int x, int y)
{
    this->health = MAX_HEALTH;


    this->scene = scene;
    this->id = id;
    collider = new Collider(x, y, SPRITE_WIDTH, SPRITE_HEIGHT, false);

    // Set Sprite
    sf::RectangleShape* render = new sf::RectangleShape();

    // Ensure sprite is loaded
    if (!crew_texture.loadFromFile("Resources\\Pirates\\Overview\\crewmate_default.png")) {
        std::cout << "Failed to load overview ship texture";
    }

    // Set sprite details
    render->setTexture(&crew_texture);
    render->setPosition(x, y);
    render->setRotation(SPRITE_ANGLE);
    render->setSize(sf::Vector2f(SPRITE_WIDTH, SPRITE_HEIGHT));

    this->render = render;
}

int Crewmate_GO::getHealth()
{
    return health;
}