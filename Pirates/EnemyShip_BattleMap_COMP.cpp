#include "EnemyShip_BattleMap_COMP.h"

# define PI           3.14159265358979323846

EnemyShip_BattleMap_COMP::EnemyShip_BattleMap_COMP( Scene* scene, EnemyShip_BattleMap_GO* self ) {
    this->scene = scene;
    this->self = self;
}

void EnemyShip_BattleMap_COMP::update( long currentTime, long deltaTime ) {

    /**
    // Set rotation
    self->render->setRotation( self->angle );
    
    self->velocity.x = sin(self->angle * PI / 180);
    self->velocity.y = cos(self->angle * PI / 180);
    
    //Calcualte new position
    float tempx = self->velocity.x * self->speed * deltaTime + self->collider->getX() ;
    float tempy = -self->velocity.y * self->speed * deltaTime + self->collider->getY();
    
    //Raise event to move ship 
    Event* e = new Event("EnemyShip_BattleMap_Move", currentTime, scene->id);
    Variant* v1 = new Variant("x", VFLOAT);
    v1->f = tempx;
    e->addParam(v1);
    Variant* v2 = new Variant("y", VFLOAT);
    v2->f = tempy;
    e->addParam(v2);
    scene->eventManager->raise(e);
    */
}