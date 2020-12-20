#include "ShipWeapons_COMP.h"

# define PI           3.14159265358979323846

ShipWeapons_COMP::ShipWeapons_COMP(Scene* scene, GameObject* self) {
    this->scene = scene;
    this->self = self;
}

void ShipWeapons_COMP::update(long currentTime, long deltaTime) {

}

bool ShipWeapons_COMP::inRange(float otherX, float otherY, int faceAngle, int angleRange, float range) {
    
    float distance = sqrt((self->collider->getX() - otherX) * (self->collider->getX() - otherX) + (self->collider->getY() - otherY) * (self->collider->getY() - otherY));
    if (distance > range) {
        return false;
    }


    //Find the actual angle to target
    float xDirection = otherX - self->collider->getX();
    float yDirection = otherY - self->collider->getY();

    float mag = sqrt(xDirection * xDirection + yDirection * yDirection);

    xDirection /= mag;
    yDirection /= mag;

    int targetAngle = atan(xDirection / yDirection) * 180 / PI;

    //Adjust the angle to coord space
    if (yDirection >= 0) {
        targetAngle += 180;
    }
    targetAngle *= -1;
    targetAngle += 180;
    if (targetAngle >= 360) {
        targetAngle -= 360;
    }
    if (targetAngle < 0) {
        targetAngle += 360;
    }
    
    //Make angle relative to facing
    targetAngle -= self->collider->getAngle();
    if (targetAngle < 0) {
        targetAngle += 360;
    }
    

    int angleDiff = (faceAngle - targetAngle + 180 + 360) % 360 - 180;

    if (angleDiff < angleRange && angleDiff > -angleRange) {
        return true;
    }
    return false;
}
