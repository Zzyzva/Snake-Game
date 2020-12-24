#pragma once

#include "Component.h"
#include "Crewmate_GO.h"

class Crewmate_GO;

/**
 * Class to represent a member of a ship's crew component
 * 
 * @author Jack
 */
class Crewmate_COMP : public Component
{
    Scene* scene;
    Crewmate_GO* self;

    /**
     * Constructor for crewmate component
     * 
     * @param scene - Scene for the component
     * @param self - Crewmate's game object
     */
    Crewmate_COMP(Scene* scene, Crewmate_GO* self);

    /**
     * Updates the crewmates movement
     * 
     * @param currentTime - ???
     * @param deltaTime - ???
     */
    void update(long currentTime, long deltaTime);
};