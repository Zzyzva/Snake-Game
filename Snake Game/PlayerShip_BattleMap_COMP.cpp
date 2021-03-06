#include "PlayerShip_BattleMap_COMP.h"

# define PI           3.14159265358979323846

PlayerShip_BattleMap_COMP::PlayerShip_BattleMap_COMP(Scene* scene, PlayerShip_BattleMap_GO* self) {
    this->scene = scene;
    this->self = self;
}

void PlayerShip_BattleMap_COMP::update(long currentTime, long deltaTime) {


    //Set rotation of sprite
    self->render->setRotation(self->angle);

    //Calculate direction based on angle
    self->velocity.x = sin(self->angle * PI / 180);
    self->velocity.y = cos(self->angle * PI / 180);


    //Calcualte new position
    float tempx = self->velocity.x * self->speed + self->collider->getX();
    float tempy = -self->velocity.y * self->speed + self->collider->getY();


    //Raise event to move ship 
    Event* e = new Event("PlayerShip_BattleMap_Move", currentTime, scene->id);
    Variant* v1 = new Variant("x", VFLOAT);
    v1->f = tempx;
    e->addParam(v1);
    Variant* v2 = new Variant("y", VFLOAT);
    v2->f = tempy;
    e->addParam(v2);
    scene->eventManager->raise(e);

    

}