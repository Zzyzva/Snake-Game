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
                float tempLeft = self->velocity.x * i * step + self->collider->getLeft();
                float tempRight = self->velocity.x * i * step + self->collider->getRight();
                float tempTop = self->velocity.y * i * step + self->collider->getTop();
                float tempBottom = self->velocity.y * i * step + self->collider->getBottom();
                if (tempLeft < other->collider->getRight() 
                    && tempRight > other->collider->getLeft() 
                    && tempTop < other->collider->getBottom() 
                    && tempBottom > other->collider->getTop()) {
                    std::cout << "You're gonna crash!" << std::endl;

                    float tempx = self->velocity.x * i * step + self->collider->getX();
                    float tempy = self->velocity.x * i * step + self->collider->getY();

                    float other_tempx = other->collider->getX() + other->collider->getWidth() / 2;
                    float other_tempy = other->collider->getY() + other->collider->getHeight() / 2;

                    float angleChange = 0;
                    int angleAdjust = 5;
                    int count = 1;
                    
                    while (angleChange == 0) {
                        angleAdjust *= -1;
                        if (count % 2 == 0) {
                            angleAdjust += 5;
                        }
                        float tempAngle = self->angle + angleAdjust;
                        if (tempAngle >= 360) {
                            tempAngle -= 360;
                        }
                        else if (tempAngle < 0) {
                            tempAngle += 360;
                        }

                        if (angleAdjust > 180) {
                            break;
                        }

                        float tempVelX = -sin(tempAngle * PI / 180);
                        float tempVelY = cos(tempAngle * PI / 180);


                        float tempLeft = tempVelX * i * step + self->collider->getLeft();
                        float tempRight = tempVelX * i * step + self->collider->getRight();
                        float tempTop = tempVelY * i * step + self->collider->getTop();
                        float tempBottom = tempVelY * i * step + self->collider->getBottom();


                        //If there is not a collision
                        if (!(tempLeft < other->collider->getRight()
                            && tempRight > other->collider->getLeft()
                            && tempTop < other->collider->getBottom()
                            && tempBottom > other->collider->getTop())) {

                            if (angleAdjust > 0) {
                                angleChange = 1;
                                std::cout << "Turn Right!" << std::endl;
                            }
                            else {
                                angleChange = -1;
                                std::cout << "Turn Left!" << std::endl;
                            }
                        }
                        count++;
                    }


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