#include "Ship_GUI_GO.h"

/** Width of the ship sprite */
static constexpr int const& SPRITE_WIDTH = 250;

/** Height of the ship sprite */
static constexpr int const& SPRITE_HEIGHT = 500;

/** Direction ship is facing */
static constexpr int const& SPRITE_ANGLE = 90;


Ship_GUI_GO::Ship_GUI_GO(Scene* scene, int id, int x, int y)
{
    this->scene = scene;
    this->id = id;
    collider = new Collider(x, y, SPRITE_WIDTH, SPRITE_HEIGHT, false);

    // Set Sprite
    sf::RectangleShape* render = new sf::RectangleShape();

    // Ensure sprite is loaded
    if (!overview_texture.loadFromFile( "Resources\\Pirates\\PlayerShip_BattleMap_Sprite.png" )) {
        std::cout << "Failed to load overview ship texture";
    }

    // Set sprite details
    render->setTexture( &overview_texture );
    render->setPosition( x, y );
    render->setRotation( SPRITE_ANGLE );
    render->setSize( sf::Vector2f( SPRITE_WIDTH, SPRITE_HEIGHT ) );

    this->render = render;
}