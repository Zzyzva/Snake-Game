#pragma once

#include "Component.h"

/**
 * Component for a generic ship's health system
 * 
 * @author Jack
 */
class ShipHealth_COMP : public Component
{
private:
    Scene* scene;
    GameObject* self;

    /** Ticks per second in the game. We probably need to make a way to get this programattically */
    const int TICKS_PER_SECOND = 50;

    /** Level of water that causes ship to sink (max water level) */
    int threshold;

    /** Current level of water on the ship (defaults to 0) */
    int waterLevel;

    /** Current rate that the water level is changing (defaults to 0) */
    int rate;

    /** Time the water level was updated last. Used to make the 1 irl second calculation */
    int lastUpdateTime;

    /** Flag for whether or not the ship is "dead" */
    bool sunk;

public:

    /**
     * Constructor for the ship health component
     * 
     * @param scene - Scene of the component
     * @param self - GameObject that is using this component
     * @param threshold - Amount of water that causes the ship to sink. Equivalent to the ship's "max health"
     */
    ShipHealth_COMP(Scene* scene, GameObject* self, int threshold);

    /**
     * Update method to be run every tick
     * 
     * @param currentTime - Time that is currently being processed
     * @param deltaTime - Time change since last tick
     */
    void update(long currentTime, long deltaTime);

    int getThreshold();

    void setThreshold(int threshold);

    /**
     * Returns whether or not the ship has been sunk
     * 
     * @return bool - True if the ship is "dead", false otherwise
     */
    bool getSunk();

    void setSunk(bool sunk);

    /**
     * Returns the water level of the ship
     * 
     * @return int - Water level of the ship
     */
    int getWaterLevel();

    void setWaterLevel(int level);

    /**
     * Returns the ship's water intake rate
     * 
     * @return int - Ship's water intake rate
     */
    int getRate();

    /**
     * Sets the ship's water intake rate
     * 
     * @param rate - New value for the ship's water intake rate
     */
    void setRate(int rate);

    /**
     * Adds the provided rate to the actual rate. Saves time with get/set. Adding a negative number will subtract from the rate.
     * 
     * @param add - Value to be added to the rate. Works for both positive and negative values.
     */
    void addToRate(int add);
};