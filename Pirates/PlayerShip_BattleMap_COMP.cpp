#include "PlayerShip_BattleMap_COMP.h"

# define PI           3.14159265358979323846

PlayerShip_BattleMap_COMP::PlayerShip_BattleMap_COMP(Scene* scene, PlayerShip_BattleMap_GO* self) {
    this->scene = scene;
    this->self = self;
}

void PlayerShip_BattleMap_COMP::update(long currentTime, long deltaTime) {


    for (auto entry : *scene->getObjects()) {
        GameObject* other = entry.second;
        if (other->collider->isSolid() && other != self) {
            int step = 20;
            for (int i = 0; i < 8; i++) {
                float tempx = self->velocity.x * i * step + self->collider->getX();
                float tempy = self->velocity.y * i * step + self->collider->getY();
                if (tempx > other->collider->getLeft() && tempx < other->collider->getRight() && tempy < other->collider->getBottom() && tempy > other->collider->getTop()) {
                    std::cout << "You're gonna crash!" << std::endl;
                    break;
                }
            }
            
        }

    }


    //If the ship has a target
    if (self->targeting) {

        //Find the angle that would point at the target
        float xDirection = self->target.x - self->collider->getX();
        float yDirection = self->target.y - self->collider->getY();

        float mag = sqrt(xDirection * xDirection + yDirection * yDirection);

        xDirection /= mag;
        yDirection /= mag;

        int targetAngle = atan(xDirection / yDirection) * 180 / PI;

        //Adjust the angle to coord space
        if (yDirection >= 0) {
            targetAngle += 180;
        }
        targetAngle *= -1;
        if (targetAngle >= 360) {
            targetAngle -= 360;
        }
        if (targetAngle < 0) {
            targetAngle += 360;
        }
        
        //Check if target angle is left or right of current angle
        //First adjust all angles to 180 reference
        int actualTemp = self->angle;
        if (targetAngle > 180) {  
            actualTemp -= targetAngle - 180;
        }
        if (targetAngle < 180) {
            actualTemp += 180 - targetAngle;
        }

        if (actualTemp >= 360) {
            actualTemp -= 360;
        }
        if (actualTemp < 0) {
            actualTemp += 360;
        }
        
        //Then check if left or right
        int angleChange = 0;
        if (actualTemp < 180) {
            angleChange = -1;
        }
        if (actualTemp > 180) {
            angleChange = 1;
        }

        //Set new angle PUT THIS IN AN EVENT
        self->angle += angleChange;
        if (self->angle >= 360) {
            self->angle -= 360;
        }
        if (self->angle < 0) {
            self->angle += 360;
        }

        //Set new velocity
        self->velocity.x = -sin(self->angle * PI / 180);
        self->velocity.y = cos(self->angle * PI / 180);

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