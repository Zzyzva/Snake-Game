#include "ShipHealth_COMP.h"

ShipHealth_COMP::ShipHealth_COMP(Scene* scene, GameObject* self, int threshold)
{
    this->scene = scene;
    this->self = self;

    // Max "health" of the ship
    this->threshold = threshold;

    // Water level and rate start at 0 (theoretically this could change for rogue-like purposes, but for now it's not important)
    this->waterLevel = 0;
    this->rate = 0;

    this->sunk = false;

    this->lastUpdateTime = -1;
}

void ShipHealth_COMP::update(long currentTime, long deltaTime)
{
    // If this is the first tick, update the last time variable
    if( lastUpdateTime == -1 ) {
        lastUpdateTime = currentTime;
    }

    // Update the threshold every irl second, but only if the rate is non-zero
    if (rate != 0 && currentTime - lastUpdateTime >= TICKS_PER_SECOND) {
        lastUpdateTime = currentTime;

        waterLevel += rate; // Will work for positive or negative rates

        if (waterLevel < 0) {
            waterLevel = 0;
        }

        if (waterLevel >= threshold) {
            waterLevel = threshold;
            sunk = true;
        }
    }
    
}

bool ShipHealth_COMP::getSunk()
{
    return sunk;
}

int ShipHealth_COMP::getWaterLevel()
{
    return waterLevel;
}

int ShipHealth_COMP::getRate()
{
    return rate;
}

void ShipHealth_COMP::setRate( int rate )
{
    this->rate = rate;
}

void ShipHealth_COMP::addToRate(int add)
{
    this->rate += add;
}