#include "PlayerShip_BattleMap_COMP.h"

# define PI           3.14159265358979323846

PlayerShip_BattleMap_COMP::PlayerShip_BattleMap_COMP(Scene* scene, PlayerShip_BattleMap_GO* self) {
    this->scene = scene;
    this->self = self;
}

void PlayerShip_BattleMap_COMP::update(long currentTime, long deltaTime) {



    if (self->targeting) {
        float xDirection = self->target.x - self->collider->getX();
        float yDirection = self->target.y - self->collider->getY();

        float mag = sqrt(xDirection * xDirection + yDirection * yDirection);

        xDirection /= mag;
        yDirection /= mag;

        float xForce = xDirection - self->velocity.x;
        float yForce = yDirection - self->velocity.y;

        xForce /= 50;
        yForce /= 50;

        float newXVelocity = self->velocity.x + xForce;
        float newYVelocity = self->velocity.y + yForce;

        float mag2 = sqrt(newXVelocity * newXVelocity + newYVelocity * newYVelocity);

        newXVelocity /= mag2;
        newYVelocity /= mag2;

        self->velocity.x = newXVelocity;
        self->velocity.y = newYVelocity;
    }
    
    float tempx = self->velocity.x * self->speed * deltaTime + self->collider->getX();
    float tempy = self->velocity.y * self->speed * deltaTime + self->collider->getY();

    if (tempx < self->target.x + 5 && tempx > self->target.x - 5 && tempy < self->target.y + 5 && tempy > self->target.y) {
        self->targeting = false;
    }

    int angle = atan(self->velocity.x / self->velocity.y) * 180 / PI;

    if (self->velocity.y >= 0) {
        angle += 180;
    }
    self->render->setRotation(-angle);

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