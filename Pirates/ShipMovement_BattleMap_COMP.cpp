#include "ShipMovement_BattleMap_COMP.h"

# define PI           3.14159265358979323846

ShipMovement_BattleMap_COMP::ShipMovement_BattleMap_COMP(Scene* scene, GameObject* self) {
    this->scene = scene;
    this->self = self;
    velocity.x = 0;
    velocity.y = 0;
    target.x = 0;
    target.y = 0;
}

void ShipMovement_BattleMap_COMP::update(long currentTime, long deltaTime) {
    int selfAngle = self->collider->getAngle();
    bool adjusting = false;

    //Check each object if we will crash
    for (auto entry : *scene->getObjects()) {
        GameObject* other = entry.second;
        if (other->collider->isSolid() && other != self) {
            int step = 20;
            for (int i = 0; i < 8; i++) {
                float tempLeft = velocity.x * i * step + self->collider->getLeft();
                float tempRight = velocity.x * i * step + self->collider->getRight();
                float tempTop = velocity.y * i * step + self->collider->getTop();
                float tempBottom = velocity.y * i * step + self->collider->getBottom();

                //If current path leads to a collision
                if (tempLeft < other->collider->getRight() 
                    && tempRight > other->collider->getLeft() 
                    && tempTop < other->collider->getBottom() 
                    && tempBottom > other->collider->getTop()) {

                    float tempx = velocity.x * i * step + self->collider->getX();
                    float tempy = velocity.x * i * step + self->collider->getY();

                    float other_tempx = other->collider->getX() + other->collider->getWidth() / 2;
                    float other_tempy = other->collider->getY() + other->collider->getHeight() / 2;

                    float angleChange = 0;
                    int angleAdjust = 5;
                    int count = 1;
                    
                    //Check which way to turn
                    while (angleChange == 0) {
                        angleAdjust *= -1;
                        if (count % 2 == 0) {
                            angleAdjust += 5;
                        }
                        float tempAngle = selfAngle + angleAdjust;
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
                                adjusting = true;
                                //std::cout << "Turn Right!" << std::endl;
                            }
                            else {
                                angleChange = -1;
                                adjusting = true;
                                //std::cout << "Turn Left!" << std::endl;
                            }
                        }
                        count++;
                    }
                    
                    selfAngle += angleChange;
                    if (selfAngle >= 360) {
                        selfAngle -= 360;
                    }
                    if (selfAngle < 0) {
                        selfAngle += 360;
                    }
                    break;
                }
            } 
        }
    }


    //If the ship has a target
    if (targeting && !adjusting) {

        //Find the angle that would point at the target
        float xDirection = target.x - self->collider->getX();
        float yDirection = target.y - self->collider->getY();

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
        int actualTemp = self->collider->getAngle();;
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

        //Set new angle
        selfAngle += angleChange;
        if (selfAngle >= 360) {
            selfAngle -= 360;
        }
        if (selfAngle < 0) {
            selfAngle += 360;
        }
    }
    
    velocity.x = -sin(selfAngle * PI / 180);
    velocity.y = cos(selfAngle * PI / 180);

    float tempx = velocity.x * speed * deltaTime + self->collider->getX();
    float tempy = velocity.y * speed * deltaTime + self->collider->getY();
    float mag = sqrt((tempx - target.x) * (tempx - target.x) + (tempy - target.y) * (tempy - target.y));

    if (pathing == false) {
        if (mag < 40) {
            if (speed > .02) {
                speed -= .02;
            }
        }

        if (mag < 4) {
            speed = 0;
            targeting = false;
        }
    }
    else {
        if (mag < 4) {
            target = targetQueue.front();
            targetQueue.push(targetQueue.front());
            targetQueue.pop();
        }
    }
    
    self->render->setRotation(selfAngle - 180);

    //Raise event to move ship 
    Event* e = new Event("ShipMovement" + self->id, currentTime, scene->id);
    Variant* v1 = new Variant("x", VFLOAT);
    v1->f = tempx;
    e->addParam(v1);
    Variant* v2 = new Variant("y", VFLOAT);
    v2->f = tempy;
    e->addParam(v2);
    Variant* v3 = new Variant("angle", VINT);
    v3->i = selfAngle;
    e->addParam(v3);
   
    scene->eventManager->raise(e);

    

    

}