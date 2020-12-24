#include "EnemyShip_BattleMap_GO.h"

static constexpr int const& SPRITE_SIZE = 128;

EnemyShip_BattleMap_GO::EnemyShip_BattleMap_GO( Scene* scene, int id, int x, int y, int playerShipID ) {
    this->scene = scene;
    this->id = id;
    this->playerShipID = playerShipID;
    
    collider = new Collider( x, y, SPRITE_SIZE, SPRITE_SIZE, true );
    
    // Set sprite
    sf::RectangleShape* render = new sf::RectangleShape();
    if( !ship_texture.loadFromFile( "Resources\\Pirates\\Turtle.png" )){
        std::cout << "Failed to load enemy ship texture";
    }
    

    collider->setAngle(160);

    render->setTexture( &ship_texture );
    render->setPosition( x,y );
    render->setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    render->setOrigin(SPRITE_SIZE / 2, SPRITE_SIZE / 2);
    render->setRotation(collider->getAngle());
    this->render = render;
    
    //Set up Movement COMP
    movement = new ShipMovement_BattleMap_COMP(scene, this);
    movement->pathing = true;
    movement->targeting = true;
    movement->target = Point(1300, 500);
    movement->targetQueue.push(Point(1300, 700));
    movement->targetQueue.push(Point(1300, 500));
    movement->speed = 1;
    addComponent( movement );

    //Set up Weapons COMP
    weapons = new ShipWeapons_COMP(scene, this);
    addComponent(weapons);

    new EnemyShip_BattleMap_EH( scene, this );
    
}