#pragma once

#include "EventHandler.h"

/**
 * Event handler for health component
 *
 * @author Jack
 */
class ShipHealth_EH : public EventHandler
{
private:
    GameObject* self;

public:

    /**
     * Constructor for event handler object
     *
     * @param scene - Event handler scene
     * @param self - Game object handler is attached to
     */
    ShipHealth_EH(Scene* scene, GameObject* self);

    /**
     * Handles events being listened for
     * 
     * @param e - Events that are listened for
     */
    void handleEvent(Event* e);
};